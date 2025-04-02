# What are attestations

> Artifact attestations enable you to create unfalsifiable provenance and integrity guarantees for the software you build. In turn, people who consume your software can verify where and how your software was built.

> When you generate artifact attestations with your software, you create cryptographically signed claims that establish your build's provenance and include the following information:

> A link to the workflow associated with the artifact.
> The repository, organization, environment, commit SHA, and triggering event for the artifact.
> Other information from the OIDC token used to establish provenance. For more information, see About security hardening with OpenID Connect.

For more details see the [GitHub attestation documentation].

[GitHub attestation documentation]: https://docs.github.com/en/actions/security-for-github-actions/using-artifact-attestations/using-artifact-attestations-to-establish-provenance-for-builds#about-artifact-attestations
