# GitHub labels

## Categories

### Process states

These labels will be assigned and removed predominantly in the "**In progress**" Kanban column ("swimlane").

| Category   | Labels                                                                                      |
|------------|---------------------------------------------------------------------------------------------|
| Problems   | ![blocked](blocked.png)                                                                     |
| Pending    | ![waiting to merge](waiting-to-merge.png) ![waiting for customer](waiting-for-customer.png) |
| Done       | ![fixed](fixed.png)                                                                         |
| Inactive   | ![duplicate](duplicate.png) ![invalid](invalid.png) ![wontfix](wontfix.png)                 |

### Non-process attributes

These labels will be assigned predominantly in the "**Backlog**", "**On deck**", and "**In progress**" Kanban columns ("swimlanes").

| Category   | Labels |
|------------|--------|
| Submitter  | ![customer-submission](customer-submission.png)             |
| Issue type | ![bug](bug.png) ![documentation](documentation.png) ![enhancement](enhancement.png) ![performance](performance.png) ![refactoring](refactoring.png) |
| Info       | ![conversation](conversation.png) ![triage](triage.png) ![question](question.png) |
| Group      | ![G2Tool](G2Tool.png) ![V3](V3.png) ![V4](V4.png)|

## Details

Labels listed in alphabetical order.

| Label text           |                                                                   | Color   | Description                                  |
|----------------------|-------------------------------------------------------------------|---------|----------------------------------------------|
| blocked              | ![FF0000](https://via.placeholder.com/30x30/FF0000/FF0000?text=.) | #FF0000 | Cannot make progress                         |
| bug                  | ![66FFFF](https://via.placeholder.com/30x30/66FFFF/66FFFF?text=.) | #66FFFF | Something isn't working                      |
| conversation         | ![CCCCFF](https://via.placeholder.com/30x30/CCCCFF/CCCCFF?text=.) | #CCCCFF | In conversation on design or usage           |
| customer-submission  | ![FFFF00](https://via.placeholder.com/30x30/FFFF00/FFFF00?text=.) | #FFFF00 | Issue submitted by customer                  |
| documentation        | ![66FFFF](https://via.placeholder.com/30x30/66FFFF/66FFFF?text=.) | #66FFFF | Improvements or additions to documentation   |
| duplicate            | ![000000](https://via.placeholder.com/30x30/000000/000000?text=.) | #000000 | This issue or pull request already exists    |
| enhancement          | ![66FFFF](https://via.placeholder.com/30x30/66FFFF/66FFFF?text=.) | #66FFFF | New feature request                          |
| fixed                | ![00FF00](https://via.placeholder.com/30x30/00FF00/00FF00?text=.) | #00FF00 | Fixed. Waiting for issue creator to close    |
| G2Tool               | ![0000FF](https://via.placeholder.com/30x30/0000FF/0000FF?text=.) | #0000FF | Concerns G2Tools package                     |
| go                   | ![16E2E2](https://via.placeholder.com/30x30/16E2E2/16E2E2?text=.) | #16E2E2 | Go programming language                      |
| invalid              | ![000000](https://via.placeholder.com/30x30/000000/000000?text=.) | #000000 | This doesn't seem right                      |
| java                 | ![FFA221](https://via.placeholder.com/30x30/FFA221/FFA221?text=.) | #FFA221 | Java programming language                    |
| performance          | ![66FFFF](https://via.placeholder.com/30x30/66FFFF/66FFFF?text=.) | #66FFFF | Correct behavior, but slow performance       |
| python               | ![2B67C6](https://via.placeholder.com/30x30/2B67C6/2B67C6?text=.) | #2B67C6 | Python programming language                  |
| question             | ![CCCCFF](https://via.placeholder.com/30x30/CCCCFF/CCCCFF?text=.) | #CCCCFF | User-submitted question                      |
| refactoring          | ![66FFFF](https://via.placeholder.com/30x30/66FFFF/66FFFF?text=.) | #66FFFF | No behavioral change, internal restructuring |
| triage               | ![CCCCFF](https://via.placeholder.com/30x30/CCCCFF/CCCCFF?text=.) | #CCCCFF | Need to triage                               |
| V3                   | ![0000FF](https://via.placeholder.com/30x30/0000FF/0000FF?text=.) | #0000FF | Needed for Senzing V3                        |
| waiting-for-customer | ![FF9900](https://via.placeholder.com/30x30/FF9900/FF9900?text=.) | #FF9900 | Customer needs to verify fix or close issue  |
| waiting-to-merge     | ![FF9900](https://via.placeholder.com/30x30/FF9900/FF9900?text=.) | #FF9900 | Code complete, cannot merge yet              |
| wontfix              | ![000000](https://via.placeholder.com/30x30/000000/000000?text=.) | #000000 | This will not be worked on                   |

## Colors used

1. 000000
1. 0000FF
1. 00FF00
1. 16E2E2 - go
1. 2B67C6 - python
1. 66FFFF
1. CCCCFF
1. FF0000
1. FF9900
1. FFA221 - java
1. FFFF00

## References

1. [How we organize GitHub issues: A simple styleguide for tagging](https://robinpowered.com/blog/best-practice-system-for-organizing-and-tagging-github-issues/)
1. [Web safe color chart](https://htmlcolorcodes.com/color-chart/web-safe-color-chart/)
1. [Senzing repository labels](https://github.com/organizations/Senzing/settings/labels) - may only be available to account admins
1. Legacy tags:
   1. accepted
   1. bug
   1. conversation
   1. dependencies
   1. documentation
   1. duplicate
   1. enhancement
   1. fixed
   1. invalid
   1. open
   1. performance
   1. question
   1. refactoring
   1. testing
   1. wontfix
