# How to verify a container signature

Senzing container image signatures are automatically verified after signing.
See the [sign image composite action] for more details.

## Verifying images outside of github actions

See the [cosign verification documentation] for more details.
You will not need a key as we are using the GitHub OIDC token to sign images.
See [Keyless verification using OpenID Connect] for more details.

1. [Install cosign]
1. Update values encased in `<>` in the following
   ```console
   cosign verify --certificate-oidc-issuer=https://token.actions.githubusercontent.com \
        --certificate-identity=https://github.com/<REPOSITORY_WORKFLOW_PATH>:@refs/tags/<image TAG> \
        <image URI>:<image TAG>
   ```
   Ex.
   ```console
   cosign verify --certificate-oidc-issuer=https://token.actions.githubusercontent.com \
        --certificate-identity=https://github.com/senzing-garage/test-ground/.github/workflows/docker-push-containers-to-dockerhub-and-ecr.yaml@refs/tags/0.0.19 \
        docker.io/senzing/test-ground:0.0.19
   ```
   HINT: For all community repositories the workflow file should be one of the values listed below.
   You can find the workflow in `.github/workflows` in the respective github repository for the image.
   - docker-push-containers-to-dockerhub.yaml
   - docker-push-containers-to-dockerhub-and-ecr.yaml
1. Signature payloads created by cosign included the digest of the container image they are attached to.
   By default, cosign validates that this digest matches the container during cosign verify

[Keyless verification using OpenID Connect]: https://docs.sigstore.dev/cosign/verifying/verify/#keyless-verification-using-openid-connect
[Install cosign]: /WHATIS/cosign.md#Install
[sign image composite action]: https://github.com/senzing-factory/github-action-docker-buildx-build/blob/main/signing/action.yaml
