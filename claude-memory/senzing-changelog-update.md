# Senzing versioned release

1. If no $ARGUMENTS specified, ask user to choose a subcommand from the following list:
    1. major - Made incompatible API changes. Creates {new-semantic-version}.
    1. minor - Added functionality in a backward compatible manner. Creates {new-semantic-version}.
    1. patch - Made backward compatible bug fixes. Creates {new-semantic-version}.

1. If subcommand is "major", in `CHANGELOG.md`, add a new "Major version" section.
1. If subcommand is "minor", in `CHANGELOG.md`, add a new "Minor version" section.
1. If subcommand is "patch", in `CHANGELOG.md`, add a new "Patch version" section.
1. In new `CHANGELOG.md` section:
    1. In "Added to {semantic-version}" section, report new functionality since last versioned release in human terms.
    2. In "Changed in {semantic-version}" section, report modified functionality since last versioned release in human terms.
    3. In "Removed from {semantic-version}" section, report deleted functionality since last versioned release in human terms.
    4. In "Fixed in {semantic-version}" section, report fixes since last versioned release in human terms.
    5. Do not include changes to any folders or files starting with a dot (".").
    6. Adhere to the following standards:
        1. <https://keepachangelog.com/en/1.0.0/>
        2. <https://semver.org/spec/v2.0.0.html>
