# GitHub Organization Settings, Configuration, and Standards

## Secrets and Token Naming Conventions

- Secret and token names should be prefixed with the corresponding service. Ex:
  ```console
  AWS_<SECRET_NAME>
  DOCKERHUB_<SECRET_NAME>
  SENZING_GITHUB_<SECRET_NAME>
  ```
  - We include the `SENZING` Community name prefix for all GitHub secrets due to [GitHub restrictions].
- The remaining secret name should allude to the purpose of the secret/token and the level of permissions where applicable. Ex.
  ```console
  SENZING_GITHUB_CODEOWNER_PR_RW_TOKEN
  ```

#### CODEOWNER Token Configuration

Used for automated approvals on dependabot pull requests.

1. Create a fine-grained personal access token (CODEOWNER)

   1. Click your profile photo, then click `Settings`.
   1. In the left sidebar, click `Developer settings`.
   1. In the left sidebar, under `Personal access tokens`
      1. click `Fine-grained tokens`.
   1. Click `Generate new token`.
   1. Under `Token name`, enter a name for the token: `SENZING_GITHUB_CODEOWNER_PR_RW_TOKEN`.
   1. Under `Expiration`, select an expiration for the token.
   1. Optionally, under `Description`, describe the purpose of the token.
   1. Under `Resource owner`, select a resource owner: `Senzing`.
      - See [Token Docs] for additional details.
   1. Under `Repository access`, select: `All repositories`
   1. Under `Permissions` > `Repository Permissions` > `Pull requests`
      1. Select `Access: Read and write` in the dropdown.
   1. Click `Generate token`.
   1. Copy the new token for use in Step 2.

2. Add the newly generated token in step 1 as an organization secret for Dependabot.
   - Note: To create secrets at the organization level, you must have admin access.
   1. On GitHub.com, navigate to the main page of the organization.
   1. Under your organization name, click `Settings`.
   1. Expand `* Secrets and variables` in the left side nav.
      1. Select `Dependabot`.
   1. Click `New organization secret`.
   1. In the `Name` input box type: `SENZING_GITHUB_CODEOWNER_PR_RW_TOKEN`.
   1. From the `Repository access` dropdown list, choose `All repositories`.
   1. Input the token generated in step one into the text box.
   1. Click `Add secret`.

[GitHub restrictions]: https://docs.github.com/en/actions/security-guides/encrypted-secrets
[Token Docs]: https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/managing-your-personal-access-tokens#creating-a-fine-grained-personal-access-token
