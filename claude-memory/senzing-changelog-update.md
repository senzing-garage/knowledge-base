# Senzing versioned release

1. If no $ARGUMENTS specified, show the user the current {semantic-version}
   and ask user to choose a subcommand from the following list. Show user {new-semantic-version} for each choice.
    1. major - Made incompatible API changes. New version would be {new-semantic-version}.
    1. minor - Added functionality in a backward compatible manner.  New version would be {new-semantic-version}.
    1. patch - Made backward compatible bug fixes.  New version would be {new-semantic-version}.

1. If subcommand is "major", in `CHANGELOG.md`, add a new "Major version" section.
1. If subcommand is "minor", in `CHANGELOG.md`, add a new "Minor version" section.
1. If subcommand is "patch", in `CHANGELOG.md`, add a new "Patch version" section.
1. In new `CHANGELOG.md` section:
    1. In "Added to {new-semantic-version}" section, report new functionality since last versioned release in human terms.
    2. In "Changed in {new-semantic-version}" section, report modified functionality since last versioned release in human terms.
    3. In "Removed from {new-semantic-version}" section, report deleted functionality since last versioned release in human terms.
    4. In "Fixed in {new-semantic-version}" section, report fixes since last versioned release in human terms.
    5. Do not include changes to any folders or files starting with a dot (".").
    6. Adhere to the following standards:
        1. <https://keepachangelog.com/en/1.0.0/>
        2. <https://semver.org/spec/v2.0.0.html>
