# How to bring up an ELK stack

The following gives steps and an outline on how to bring up an ELK stack for docker-compose stacks. This page assumes a working knowledge of docker and docker-compose.

## Prerequisites
1. [docker](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-docker.md) - minimum version: [20.10.16](https://docs.docker.com/engine/release-notes/#201016)
2. [docker-compose](https://github.com/Senzing/knowledge-base/blob/main/HOWTO/install-docker-compose.md) - minimum version: [1.29.0](https://docs.docker.com/compose/release-notes/#1290)
3. [elasticsearch](https://www.elastic.co/guide/en/elasticsearch/reference/current/install-elasticsearch.html) - minimum version: [8.5.3](https://www.elastic.co/guide/en/elasticsearch/reference/current/release-highlights.html)


### Notes
This example simply shows the containers for the ELK stack in a docker-compose form to be able to connect
with other containers. This example is easily expandable and if the containers to log are brought up with
docker-compose they can be added to the example `yaml` given below or brought up in a seperate `yaml`.

If the 'containers to log' are brought up seperately from the ELK stack `yaml` then these are the most
important requirements

- The 'containers to log' use the same `NETWORK` as the ELK stack
- `Elasticsearch`, `kibana`, and `logstash`, are not present in any `depends_on` sections
- Each container to log has a logging field (This is also required if the containers are in the same `yaml`). Example:
``` yaml
  logging:
      driver: gelf
      options:
        gelf-address: "udp://<hostIP>:12201"
        tag: "container-to-log"
```

### 📘 Instructions
- Create the `ELK-docker-compose.yaml` that is used to bring up the ELK stack. This is simply the set
of containers needed for the ELK stack, create a new `yaml` with the following:

<details>
  <summary>example docker-compose.yaml</summary>
  
``` yaml
version: '3'
services:

  elasticsearch:
    container_name: senzing-elasticsearch
    environment:
      discovery.type: single-node
      ES_JAVA_OPTS: "-Xmx256m -Xms256m"
      xpack.security.enabled: 'false'
    image: elasticsearch:${SENZING_DOCKER_IMAGE_VERSION_ELASTICSEARCH:-latest}
    networks:
      - senzing
    ports:
      - 9200:9200
      - 9300:9300
    restart: always
 
  logstash:
    command:
      - --config.string
      - >-
        input {
          gelf {
            port => 12201
          }
        }
        output {
          elasticsearch {
            hosts => ["http://elasticsearch:9200"]
            index => "logstash-%{+YYYY-MM-dd}"
          }
        }
    container_name: senzing-logstash
    environment:
      LS_JAVA_OPTS: "-Xmx256m -Xms256m"
    image: logstash:${SENZING_DOCKER_IMAGE_VERSION_LOGSTASH:-latest}
    logging:
      driver: gelf
      options:
        gelf-address: "udp://localhost:12201"
        tag: "senzing-logstash"
    networks:
      - senzing
    ports:
      - 9600:9600
      - 12201:12201/udp
    restart: always
    
  kibana:
    container_name: senzing-kibana
    depends_on:
      - elasticsearch
      - logstash
    image: kibana:${SENZING_DOCKER_IMAGE_VERSION_KIBANA:-latest}
    networks:
      - senzing
    ports:
      - 5601:5601
    restart: always
    
networks:
  senzing:
    name: ${SENZING_DOCKER_NETWORK:-senzing-network}
```
  optionally, a pre-made dashboard for kibana can be imported by adding this "container" that runs a script to add it
``` yaml
    kibana-dashboard:
    container_name: senzing-kibana-dashboard
    command:
      - sh
      - -c
      - |
        apk update
        apk upgrade
        apk add bash
        echo $${UPLOAD_FILE} | base64 -d >  /tmp/upload.sh;
        echo $${EXPORT_FILE} | base64 -d > /tmp/export.ndjson;
        chmod a+x /tmp/upload.sh;
        bash /tmp/upload.sh
    environment:
      EXPORT_FILE: >-
        eyJhdHRyaWJ1dGVzIjp7ImZpZWxkQXR0cnMiOiJ7XCJjb250YWluZXJfbmFtZVwiOntcImNvdW50XCI6Mn0sXCJtZXNzYWdlXCI6e1wiY291bnRcIjo3fSxcInZlcnNpb25cIjp7XCJjb3VudFwiOjJ9fSIsImZpZWxkcyI6IltdIiwicnVudGltZUZpZWxkTWFwIjoie30iLCJ0aW1lRmllbGROYW1lIjoiQHRpbWVzdGFtcCIsInRpdGxlIjoibG9nKiIsInR5cGVNZXRhIjoie30ifSwiY29yZU1pZ3JhdGlvblZlcnNpb24iOiI4LjEuMyIsImlkIjoiODY4MzUxYTAtZTEwMi0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibWlncmF0aW9uVmVyc2lvbiI6eyJpbmRleC1wYXR0ZXJuIjoiOC4wLjAifSwicmVmZXJlbmNlcyI6W10sInR5cGUiOiJpbmRleC1wYXR0ZXJuIiwidXBkYXRlZF9hdCI6IjIwMjItMDUtMzFUMTc6NTg6MTUuNTMwWiIsInZlcnNpb24iOiJXell3TWl3eFhRPT0ifQp7ImF0dHJpYnV0ZXMiOnsiY29sdW1ucyI6WyJtZXNzYWdlIiwiY29udGFpbmVyX25hbWUiXSwiZGVzY3JpcHRpb24iOiJTaG93IHNlbnppbmcgbG9ncyB0aGF0IGNvbnRhaW4gZXJyb3JzIiwiZ3JpZCI6e30sImhpZGVDaGFydCI6ZmFsc2UsImtpYmFuYVNhdmVkT2JqZWN0TWV0YSI6eyJzZWFyY2hTb3VyY2VKU09OIjoie1wicXVlcnlcIjp7XCJxdWVyeVwiOlwibWVzc2FnZSA6IGVycipcIixcImxhbmd1YWdlXCI6XCJrdWVyeVwifSxcImZpbHRlclwiOltdLFwiaW5kZXhSZWZOYW1lXCI6XCJraWJhbmFTYXZlZE9iamVjdE1ldGEuc2VhcmNoU291cmNlSlNPTi5pbmRleFwifSJ9LCJzb3J0IjpbWyJAdGltZXN0YW1wIiwiZGVzYyJdXSwidGl0bGUiOiJTZW56aW5nIGVycm9yIGxvZ3MifSwiY29yZU1pZ3JhdGlvblZlcnNpb24iOiI4LjEuMyIsImlkIjoiMDBkN2EzMTAtZTEwOS0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibWlncmF0aW9uVmVyc2lvbiI6eyJzZWFyY2giOiI4LjAuMCJ9LCJyZWZlcmVuY2VzIjpbeyJpZCI6Ijg2ODM1MWEwLWUxMDItMTFlYy1hYmYxLTU5OTEyNjljOTYxZiIsIm5hbWUiOiJraWJhbmFTYXZlZE9iamVjdE1ldGEuc2VhcmNoU291cmNlSlNPTi5pbmRleCIsInR5cGUiOiJpbmRleC1wYXR0ZXJuIn1dLCJ0eXBlIjoic2VhcmNoIiwidXBkYXRlZF9hdCI6IjIwMjItMDUtMzFUMTc6NDg6MjUuMzgyWiIsInZlcnNpb24iOiJXelE0Tml3eFhRPT0ifQp7ImF0dHJpYnV0ZXMiOnsiY29sdW1ucyI6WyJtZXNzYWdlIiwiY29udGFpbmVyX25hbWUiXSwiZGVzY3JpcHRpb24iOiJTZW56aW5nIGVuZ2luZSBzdGF0cyBsb2dzIiwiZ3JpZCI6e30sImhpZGVDaGFydCI6ZmFsc2UsImtpYmFuYVNhdmVkT2JqZWN0TWV0YSI6eyJzZWFyY2hTb3VyY2VKU09OIjoie1wicXVlcnlcIjp7XCJxdWVyeVwiOlwibWVzc2FnZSA6IFxcXCJzZW56aW5nLTUwMDEwMTI1SSBHMiBlbmdpbmUgc3RhdGlzdGljc1xcXCJcIixcImxhbmd1YWdlXCI6XCJrdWVyeVwifSxcImZpbHRlclwiOltdLFwiaW5kZXhSZWZOYW1lXCI6XCJraWJhbmFTYXZlZE9iamVjdE1ldGEuc2VhcmNoU291cmNlSlNPTi5pbmRleFwifSJ9LCJzb3J0IjpbWyJAdGltZXN0YW1wIiwiZGVzYyJdXSwidGl0bGUiOiJTZW56aW5nIGVuZ2luZSBzdGF0cyBsb2dzIn0sImNvcmVNaWdyYXRpb25WZXJzaW9uIjoiOC4xLjMiLCJpZCI6IjZlMmYxZjYwLWUxMDktMTFlYy1hYmYxLTU5OTEyNjljOTYxZiIsIm1pZ3JhdGlvblZlcnNpb24iOnsic2VhcmNoIjoiOC4wLjAifSwicmVmZXJlbmNlcyI6W3siaWQiOiI4NjgzNTFhMC1lMTAyLTExZWMtYWJmMS01OTkxMjY5Yzk2MWYiLCJuYW1lIjoia2liYW5hU2F2ZWRPYmplY3RNZXRhLnNlYXJjaFNvdXJjZUpTT04uaW5kZXgiLCJ0eXBlIjoiaW5kZXgtcGF0dGVybiJ9XSwidHlwZSI6InNlYXJjaCIsInVwZGF0ZWRfYXQiOiIyMDIyLTA1LTMxVDE3OjQ4OjI1LjM4MloiLCJ2ZXJzaW9uIjoiV3pRNE55d3hYUT09In0KeyJhdHRyaWJ1dGVzIjp7ImNvbHVtbnMiOlsibWVzc2FnZSIsImNvbnRhaW5lcl9uYW1lIl0sImRlc2NyaXB0aW9uIjoiIiwiZ3JpZCI6e30sImhpZGVDaGFydCI6ZmFsc2UsImtpYmFuYVNhdmVkT2JqZWN0TWV0YSI6eyJzZWFyY2hTb3VyY2VKU09OIjoie1wicXVlcnlcIjp7XCJxdWVyeVwiOlwibWVzc2FnZSA6IFxcXCJHRVRcXFwiXCIsXCJsYW5ndWFnZVwiOlwia3VlcnlcIn0sXCJmaWx0ZXJcIjpbXSxcImluZGV4UmVmTmFtZVwiOlwia2liYW5hU2F2ZWRPYmplY3RNZXRhLnNlYXJjaFNvdXJjZUpTT04uaW5kZXhcIn0ifSwic29ydCI6W1siQHRpbWVzdGFtcCIsImRlc2MiXV0sInRpdGxlIjoiU2VuemluZyBHRVQgbG9ncyJ9LCJjb3JlTWlncmF0aW9uVmVyc2lvbiI6IjguMS4zIiwiaWQiOiJkMjhhMTRmMC1lMTBhLTExZWMtYWJmMS01OTkxMjY5Yzk2MWYiLCJtaWdyYXRpb25WZXJzaW9uIjp7InNlYXJjaCI6IjguMC4wIn0sInJlZmVyZW5jZXMiOlt7ImlkIjoiODY4MzUxYTAtZTEwMi0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibmFtZSI6ImtpYmFuYVNhdmVkT2JqZWN0TWV0YS5zZWFyY2hTb3VyY2VKU09OLmluZGV4IiwidHlwZSI6ImluZGV4LXBhdHRlcm4ifV0sInR5cGUiOiJzZWFyY2giLCJ1cGRhdGVkX2F0IjoiMjAyMi0wNS0zMVQxNzo1NToxMy45ODNaIiwidmVyc2lvbiI6Ild6VTBNeXd4WFE9PSJ9CnsiYXR0cmlidXRlcyI6eyJjb2x1bW5zIjpbIm1lc3NhZ2UiLCJjb250YWluZXJfbmFtZSJdLCJkZXNjcmlwdGlvbiI6IiIsImdyaWQiOnt9LCJoaWRlQ2hhcnQiOmZhbHNlLCJraWJhbmFTYXZlZE9iamVjdE1ldGEiOnsic2VhcmNoU291cmNlSlNPTiI6IntcInF1ZXJ5XCI6e1wicXVlcnlcIjpcIm1lc3NhZ2UgOiBcXFwic2VuemluZy01MDE3MDAwNUkgR292ZXJub3Igd2FpdGluZ1xcXCJcIixcImxhbmd1YWdlXCI6XCJrdWVyeVwifSxcImZpbHRlclwiOltdLFwiaW5kZXhSZWZOYW1lXCI6XCJraWJhbmFTYXZlZE9iamVjdE1ldGEuc2VhcmNoU291cmNlSlNPTi5pbmRleFwifSJ9LCJzb3J0IjpbWyJAdGltZXN0YW1wIiwiZGVzYyJdXSwidGl0bGUiOiJTZW56aW5nIGdvdmVybm9yIHdhaXQifSwiY29yZU1pZ3JhdGlvblZlcnNpb24iOiI4LjEuMyIsImlkIjoiZTA5NzdlNzAtZTEwYS0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibWlncmF0aW9uVmVyc2lvbiI6eyJzZWFyY2giOiI4LjAuMCJ9LCJyZWZlcmVuY2VzIjpbeyJpZCI6Ijg2ODM1MWEwLWUxMDItMTFlYy1hYmYxLTU5OTEyNjljOTYxZiIsIm5hbWUiOiJraWJhbmFTYXZlZE9iamVjdE1ldGEuc2VhcmNoU291cmNlSlNPTi5pbmRleCIsInR5cGUiOiJpbmRleC1wYXR0ZXJuIn1dLCJ0eXBlIjoic2VhcmNoIiwidXBkYXRlZF9hdCI6IjIwMjItMDUtMzFUMTc6NTU6MzcuNTU5WiIsInZlcnNpb24iOiJXelUxTXl3eFhRPT0ifQp7ImF0dHJpYnV0ZXMiOnsiZGVzY3JpcHRpb24iOiIiLCJoaXRzIjowLCJraWJhbmFTYXZlZE9iamVjdE1ldGEiOnsic2VhcmNoU291cmNlSlNPTiI6IntcInF1ZXJ5XCI6e1wicXVlcnlcIjpcIlwiLFwibGFuZ3VhZ2VcIjpcImt1ZXJ5XCJ9LFwiZmlsdGVyXCI6W119In0sIm9wdGlvbnNKU09OIjoie1widXNlTWFyZ2luc1wiOnRydWUsXCJzeW5jQ29sb3JzXCI6ZmFsc2UsXCJoaWRlUGFuZWxUaXRsZXNcIjpmYWxzZX0iLCJwYW5lbHNKU09OIjoiW3tcInZlcnNpb25cIjpcIjguMS4zXCIsXCJ0eXBlXCI6XCJzZWFyY2hcIixcImdyaWREYXRhXCI6e1wieFwiOjAsXCJ5XCI6MCxcIndcIjoyNCxcImhcIjoxNSxcImlcIjpcIjA3MjRlOGQzLTYyZDMtNDk4Yi1hYWU0LTI1ZGJjYjZhMGQzY1wifSxcInBhbmVsSW5kZXhcIjpcIjA3MjRlOGQzLTYyZDMtNDk4Yi1hYWU0LTI1ZGJjYjZhMGQzY1wiLFwiZW1iZWRkYWJsZUNvbmZpZ1wiOntcImVuaGFuY2VtZW50c1wiOnt9fSxcInBhbmVsUmVmTmFtZVwiOlwicGFuZWxfMDcyNGU4ZDMtNjJkMy00OThiLWFhZTQtMjVkYmNiNmEwZDNjXCJ9LHtcInZlcnNpb25cIjpcIjguMS4zXCIsXCJ0eXBlXCI6XCJzZWFyY2hcIixcImdyaWREYXRhXCI6e1wieFwiOjI0LFwieVwiOjAsXCJ3XCI6MjQsXCJoXCI6MTUsXCJpXCI6XCI4ZWYyNWE5NS1mY2ZlLTQ2ZDYtOGYwZC02ODhlMDczM2NjNmFcIn0sXCJwYW5lbEluZGV4XCI6XCI4ZWYyNWE5NS1mY2ZlLTQ2ZDYtOGYwZC02ODhlMDczM2NjNmFcIixcImVtYmVkZGFibGVDb25maWdcIjp7XCJlbmhhbmNlbWVudHNcIjp7fX0sXCJwYW5lbFJlZk5hbWVcIjpcInBhbmVsXzhlZjI1YTk1LWZjZmUtNDZkNi04ZjBkLTY4OGUwNzMzY2M2YVwifSx7XCJ2ZXJzaW9uXCI6XCI4LjEuM1wiLFwidHlwZVwiOlwic2VhcmNoXCIsXCJncmlkRGF0YVwiOntcInhcIjowLFwieVwiOjE1LFwid1wiOjI0LFwiaFwiOjE1LFwiaVwiOlwiNDBlNWZlNDgtNTZkMC00MjkzLThmYzMtODU2N2FjZDY0NGIxXCJ9LFwicGFuZWxJbmRleFwiOlwiNDBlNWZlNDgtNTZkMC00MjkzLThmYzMtODU2N2FjZDY0NGIxXCIsXCJlbWJlZGRhYmxlQ29uZmlnXCI6e1wiZW5oYW5jZW1lbnRzXCI6e319LFwicGFuZWxSZWZOYW1lXCI6XCJwYW5lbF80MGU1ZmU0OC01NmQwLTQyOTMtOGZjMy04NTY3YWNkNjQ0YjFcIn0se1widmVyc2lvblwiOlwiOC4xLjNcIixcInR5cGVcIjpcInNlYXJjaFwiLFwiZ3JpZERhdGFcIjp7XCJ4XCI6MjQsXCJ5XCI6MTUsXCJ3XCI6MjQsXCJoXCI6MTUsXCJpXCI6XCI3NjUyN2QyZC0xMTk2LTQ4MjYtOGMwYy1iOTNkZWQ1ZTZhMDBcIn0sXCJwYW5lbEluZGV4XCI6XCI3NjUyN2QyZC0xMTk2LTQ4MjYtOGMwYy1iOTNkZWQ1ZTZhMDBcIixcImVtYmVkZGFibGVDb25maWdcIjp7XCJlbmhhbmNlbWVudHNcIjp7fX0sXCJwYW5lbFJlZk5hbWVcIjpcInBhbmVsXzc2NTI3ZDJkLTExOTYtNDgyNi04YzBjLWI5M2RlZDVlNmEwMFwifV0iLCJ0aW1lUmVzdG9yZSI6ZmFsc2UsInRpdGxlIjoiU2VuemluZyBEYXNoYm9hcmQiLCJ2ZXJzaW9uIjoxfSwiY29yZU1pZ3JhdGlvblZlcnNpb24iOiI4LjEuMyIsImlkIjoiOThkMjBhMjAtZTEwOS0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibWlncmF0aW9uVmVyc2lvbiI6eyJkYXNoYm9hcmQiOiI4LjEuMCJ9LCJyZWZlcmVuY2VzIjpbeyJpZCI6IjAwZDdhMzEwLWUxMDktMTFlYy1hYmYxLTU5OTEyNjljOTYxZiIsIm5hbWUiOiIwNzI0ZThkMy02MmQzLTQ5OGItYWFlNC0yNWRiY2I2YTBkM2M6cGFuZWxfMDcyNGU4ZDMtNjJkMy00OThiLWFhZTQtMjVkYmNiNmEwZDNjIiwidHlwZSI6InNlYXJjaCJ9LHsiaWQiOiI2ZTJmMWY2MC1lMTA5LTExZWMtYWJmMS01OTkxMjY5Yzk2MWYiLCJuYW1lIjoiOGVmMjVhOTUtZmNmZS00NmQ2LThmMGQtNjg4ZTA3MzNjYzZhOnBhbmVsXzhlZjI1YTk1LWZjZmUtNDZkNi04ZjBkLTY4OGUwNzMzY2M2YSIsInR5cGUiOiJzZWFyY2gifSx7ImlkIjoiZDI4YTE0ZjAtZTEwYS0xMWVjLWFiZjEtNTk5MTI2OWM5NjFmIiwibmFtZSI6IjQwZTVmZTQ4LTU2ZDAtNDI5My04ZmMzLTg1NjdhY2Q2NDRiMTpwYW5lbF80MGU1ZmU0OC01NmQwLTQyOTMtOGZjMy04NTY3YWNkNjQ0YjEiLCJ0eXBlIjoic2VhcmNoIn0seyJpZCI6ImUwOTc3ZTcwLWUxMGEtMTFlYy1hYmYxLTU5OTEyNjljOTYxZiIsIm5hbWUiOiI3NjUyN2QyZC0xMTk2LTQ4MjYtOGMwYy1iOTNkZWQ1ZTZhMDA6cGFuZWxfNzY1MjdkMmQtMTE5Ni00ODI2LThjMGMtYjkzZGVkNWU2YTAwIiwidHlwZSI6InNlYXJjaCJ9XSwidHlwZSI6ImRhc2hib2FyZCIsInVwZGF0ZWRfYXQiOiIyMDIyLTA2LTAyVDE1OjAxOjQwLjcxN1oiLCJ2ZXJzaW9uIjoiV3pZME5Dd3hYUT09In0KeyJleGNsdWRlZE9iamVjdHMiOltdLCJleGNsdWRlZE9iamVjdHNDb3VudCI6MCwiZXhwb3J0ZWRDb3VudCI6NiwibWlzc2luZ1JlZkNvdW50IjowLCJtaXNzaW5nUmVmZXJlbmNlcyI6W119Cg==
      UPLOAD_FILE: >-
        IyEvYmluL2Jhc2gKd2hpbGUgOgpkbwogIHN0YXR1c19jb2RlPSQoY3VybCAtWCBQT1NUIHNlbnppbmcta2liYW5hOjU2MDEvYXBpL3NhdmVkX29iamVjdHMvX2ltcG9ydCAtSCAia2JuLXhzcmY6IHRydWUiIC0tZm9ybSBmaWxlPUAvdG1wL2V4cG9ydC5uZGpzb24gLS13cml0ZS1vdXQgIiV7aHR0cF9jb2RlfSIgLS1zaWxlbnQgLS1vdXRwdXQgL2Rldi9udWxsKQogIGlmIFtbICIkc3RhdHVzX2NvZGUiIC1uZSAyMDAgXV0gOyB0aGVuCiAgICBlY2hvICJ1bnN1Y2Nlc3NmdWwgaW1wb3J0LCB0cnlpbmcgYWdhaW4gaW4gMSBzZWNvbmQhIgogICAgc2xlZXAgMQogIGVsc2UKICAgIGVjaG8gImltcG9ydCBzdWNjZXNzIgogICAgZXhpdCAwCiAgZmkKZG9uZQo=
    image: curlimages/curl:${SENZING_DOCKER_IMAGE_VERSION_CURLIMAGES_CURL:-latest}
    networks:
      - senzing
    user: root}
```
</details>

### Bring up ELK stack
- Remember that the ELK stack takes a couple of minutes to start up, so ideally do this step before
bringing up the container you wish to log, the stack is usually fully functional when kibana is viewable;
during its startup, there will almost always be error logs.
- Make sure you are in the directory with the `yaml` for the ELK stack

```
sudo --preserve-env docker-compose -f ELK-docker-compose.yaml up
```

## View logs
- Give the ELK stack a few minutes to start and then logs are viewable in kibana at localhost:5601.
Navigate to "Analytics" -> "Discover" to see logs
