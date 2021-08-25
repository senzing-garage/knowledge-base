# XTerm security

## XTerm vs. SSHD container

The following chart compares security attributes of
[XTerm](https://github.com/Senzing/docker-xterm)
and
[sshd](https://github.com/Senzing/docker-sshd).

| Feature             | XTerm      | SSHD       | Notes                                  |
|---------------------|------------|------------| ---------------------------------------|
| Inbound CIDR        | Yes        | Yes        | Configured by cloudformation template. |
| AWS Cognito         | Yes        | No         | |
| - Unique users      | Yes        | No         | |
| - Unique passwords  | Yes        | No         | |
| - Revoke users      | Yes        | No         | |
| - MFA support       | Yes        | No         | Optional Cognito feature. |
| - Auditing          | Yes        | No         | Optional Cognito feature. |
| Network transport   | TLSv1.2    | SSH        | |
| Runs as             | 1001       | 0 - root   | Configured by cloudformation template. |
| sudo command        | No         | Yes        | |
| /opt/senzing        | read-only  | read-write | Configured by cloudformation template. |
| /etc/opt/senzing    | read-only  | read-write | Configured by cloudformation template. |
| /var/opt/senzing    | read-write | read-write | Configured by cloudformation template. |
| Individual sessions | No         | Yes        | |
| scp                 | No         | Yes        | |
| su                  | No         | Yes        | |
| adduser / useradd   | No         | Yes        | Root authority is needed to add users. |

1. **Inbound CIDR:**
   Access to the service (XTerm or SSH) can be limited by specifying a CIDR at Cloudformation deployment time.
1. **sudo command:**
   Does the `sudo` command exist?
1. **Individual sessions:**
   Does each login have an individual terminal?
   "No" means that all logged in users see exactly the same terminal.
   "Yes" means that each logged in user gets a separate terminal shell.
1. **scp:**
   Can `scp` be used to upload/download files?
1. **su:**
   Can `su` be used to switch "Run As" user?
   In "XTerm", there is no user 1001 in `/etc/passwd`, so the password for a `su` doesn't exist.

## Details

### Network traffic for socketio

Using
[wireshark](https://www.wireshark.org/),
it is seen that the network traffic for XTerm is encrypted by the TLSv1.2 protocol
and network traffic for SSH is encrypted by the SSH protocol.

#### XTerm to host traffic

In the image, five keys were hit "`test<return>`".
Five packets were sent to the host, all using TLSv1.2
When inspecting the packets, the keystrokes were not seen in cleartext.

![Traffic from XTerm to host](xterm-to-host.png)

#### Host to XTerm traffic

Filtering Wireshark with `ip.src == 52.72.230.109` to see the traffic coming back from the `52.72.230.109` host,
all five packets returned are transported using TLSv1.2.

![Traffic from host back to XTerm](host-to-xterm.png)

#### SSH traffic

In a test of `ssh`-ing into the `senzing/sshd` docker container,
all of the 5 keystrokes were sent via the "SSH" protocol.

![SSH traffic](sshd.png)
