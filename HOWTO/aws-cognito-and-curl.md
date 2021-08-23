# How to use curl with AWS Cognito

## WARNING - NOT COMPLETE

Currently these instructions are a work in progress and do not produce a successful result.
So do expect it to work, yet.

## Create App client in UserPool

1. Visit [AWS Your User pools](https://console.aws.amazon.com/cognito/users)
1. General Settings > App clients
1. Click "Add another app client"
    1. App client name: [pick anything]
    1. Expirations: [pick anything]
    1. Uncheck :black_square_button: Generate client secret
    1. Check :ballot_box_with_check: Enable username password based authentication (`ALLOW_USER_PASSWORD_AUTH`)
    1. Click "Create app client" button
1. "App client id" is used in `AWS_COGNITO_CLIENT_ID` environment variable below.

## Set enviroment

1. :pencil2: Set environment variables.
   Example:

    ```console
    export AWS_COGNITO_CLIENT_ID=xxxxxxxxxxxxxxxxxxxxxxxxxx
    export AWS_COGNITO_PASSWORD=xxxxxxxxxxxxxxxx
    export AWS_COGNITO_USERNAME=xxxxxxx@senzing.com
    export AWS_REGION=us-east-1
    export SENZING_COGNITO_PROJECT_DIR=~/test-cognito
    export SENZING_URLAPISERVERHEARTBEAT="https://.../api/heartbeat/"
    ```

    1. **AWS_COGNITO_CLIENT_ID** - from prior step
    1. **AWS_COGNITO_PASSWORD** - The password you gave after entering the "one-time" password
    1. **AWS_COGNITO_USERNAME** - From Cloudformation output *UserName*
    1. **SENZING_URLAPISERVERHEARTBEAT** - From Cloudformation output *UrlApiServerHeartbeat*

1. Create project directory.
   Example:

    ```console
    mkdir -p ${SENZING_COGNITO_PROJECT_DIR}
    ```

## Get Bearer token

1. Get Bearer token from AWS.
   Example:

    ```console
    curl -X POST \
      --verbose \
      --header 'X-Amz-Target: AWSCognitoIdentityProviderService.InitiateAuth' \
      --header 'Content-Type: application/x-amz-json-1.1' \
      --data "
        {
          \"AuthParameters\" : {
            \"USERNAME\" : \"${AWS_COGNITO_USERNAME}\",
            \"PASSWORD\" : \"${AWS_COGNITO_PASSWORD}\"
          },
          \"AuthFlow\" : \"USER_PASSWORD_AUTH\",
          \"ClientId\" : \"${AWS_COGNITO_CLIENT_ID}\"
        }
        " \
      https://cognito-idp.${AWS_REGION}.amazonaws.com/ \
      > ${SENZING_COGNITO_PROJECT_DIR}/01-get-token.json
   ```

1. Extract Bearer token from HTTP payload
   Example:

    ```console
    export SENZING_COGNITO_ACCESS_TOKEN=$(jq --raw-output ".AuthenticationResult.AccessToken" ${SENZING_COGNITO_PROJECT_DIR}/01-get-token.json)
    ```

## Make HTTP API request

1. Make HTTP request to
   Example:

    ```console
    curl -X GET \
      --include \
      --verbose \
      --location \
      --insecure \
      --header "Authorization: Bearer ${SENZING_COGNITO_ACCESS_TOKEN}" \
      ${SENZING_URLAPISERVERHEARTBEAT}
    ```
