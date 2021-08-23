# How to use curl with AWS Cognito

## Create App client in UserPool

1. Visit [AWS Your User pools](https://console.aws.amazon.com/cognito/users)
1. General Settings > [App clients](https://console.aws.amazon.com/cognito/users/?#/pool)
1. Click "Add another app client"
    1. **App client name:** [pick anything]
    1. Expirations: [pick anything]
    1. Uncheck :black_square_button: Generate client secret
    1. Check :ballot_box_with_check: Enable username password based authentication (`ALLOW_USER_PASSWORD_AUTH`)
    1. Click "Create app client" button
1. "App client id" is used in `AWS_COGNITO_CLIENT_ID` environment variable below.

## Set enviroment

1. :pencil2: Set environment variables.
   Example:

    ```console
    export AWS_REGION=us-east-1
    export AWS_COGNITO_CLIENT_ID=xxxxxxxxxxxxxxxxxxxxxxxxxx
    export AWS_COGNITO_USERNAME=xxxxxxx@senzing.com
    export AWS_COGNITO_PASSWORD=xxxxxxxxxxxxxxxx
    export SENZING_COGNITO_PROJECT_DIR=~/test-cognito
    export SENZING_UrlApiServerHeartbeat="https://stack-name-alb-public-0000000000.aws-region.elb.amazonaws.com/api/heartbeat/"
    ```

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
      --include \
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
      ${SENZING_UrlApiServerHeartbeat}
    ```
