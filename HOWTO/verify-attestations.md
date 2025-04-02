# How to verify a container attestations

See the [GitHub attestation verification documentation] for more details.

## Prerequisites

1. [Install docker]
1. [Install the GitHub CLI]

## Verify Container Attestations

Update values encased in `<>` in the following

```console
docker login docker.io

gh attestation verify --repo <GITHUB_ORGANIZATION>/<GITHUB_REPOSITORY> oci://docker.io/<DOCKER_REPOSITORY>/<IMAGE_NAME>@<IMAGE_DIGEST>
gh attestation verify --signer-repo <GITHUB_ORGANIZATION>/<GITHUB_REPOSITORY> --repo <GITHUB_ORGANIZATION>/<GITHUB_REPOSITORY> oci://docker.io/<DOCKER_REPOSITORY>/<IMAGE_NAME>@<IMAGE_DIGEST>
```

Ex.

```console
gh attestation verify --repo senzing-garage/test-ground oci://docker.io/senzing/test-ground@sha256:191b35c419171b0cea5c27d8d5ceb1bc9e9c77ba3f5e81e15fed1297fc151645
gh attestation verify --signer-repo senzing-garage/test-ground --repo senzing-garage/test-ground oci://docker.io/senzing/test-ground@sha256:191b35c419171b0cea5c27d8d5ceb1bc9e9c77ba3f5e81e15fed1297fc151645
```

NOTE: If the image is in a different registry (ex. ECR) you will need to replace the `docker.io` values

Example output:

```
Loaded digest sha256:191b35c419171b0cea5c27d8d5ceb1bc9e9c77ba3f5e81e15fed1297fc151645 for oci://docker.io/senzing/test-ground@sha256:191b35c419171b0cea5c27d8d5ceb1bc9e9c77ba3f5e81e15fed1297fc151645
Loaded 4 attestations from GitHub API

The following policy criteria will be enforced:
- Predicate type must match:................ https://slsa.dev/provenance/v1
- Source Repository Owner URI must match:... https://github.com/senzing-garage
- Source Repository URI must match:......... https://github.com/senzing-garage/test-ground
- Subject Alternative Name must match regex: (?i)^https://github.com/senzing-garage/test-ground/
- OIDC Issuer must match:................... https://token.actions.githubusercontent.com

✓ Verification succeeded!

The following 2 attestations matched the policy criteria

- Attestation #1
  - Build repo:..... senzing-garage/test-ground
  - Build workflow:. .github/workflows/docker-push-containers-to-dockerhub-and-ecr.yaml@refs/tags/0.0.19
  - Signer repo:.... senzing-garage/test-ground
  - Signer workflow: .github/workflows/docker-push-containers-to-dockerhub-and-ecr.yaml@refs/tags/0.0.19

- Attestation #2
  - Build repo:..... senzing-garage/test-ground
  - Build workflow:. .github/workflows/docker-push-containers-to-dockerhub-and-ecr.yaml@refs/tags/0.0.19
  - Signer repo:.... senzing-garage/test-ground
  - Signer workflow: .github/workflows/docker-push-containers-to-dockerhub-and-ecr.yaml@refs/tags/0.0.19
```

[GitHub attestation verification documentation]: https://docs.github.com/en/actions/security-for-github-actions/using-artifact-attestations/using-artifact-attestations-to-establish-provenance-for-builds#verifying-an-artifact-attestation-for-container-images
[Install docker]: /WHATIS/docker.md
[Install the GitHub CLI]: /WHATIS/github-cli.md
