# XTerm security

## XTerm vs. SSHD container

| Feature            | XTerm      | SSHD       | Notes                                  |
|--------------------|------------|------------| ---------------------------------------|
| Inbound CIDR       | Yes        | Yes        | Configured by cloudformation template. |
| AWS Cognito        | Yes        | No         | |
| - Unique users     | Yes        | No         | |
| - Unique passwords | Yes        | No         | |
| - Revoke users     | Yes        | No         | |
| - MFA support      | Yes        | No         | |
| Network transport  | TLSv1.2    | SSH        | |
| Runs as            | 1001       | root       | Configured by cloudformation template. |
| sudo command       | No         | Yes        | |
| /opt/senzing       | read-only  | read-write | Configured by cloudformation template. |
| /etc/opt/senzing   | read-only  | read-write | Configured by cloudformation template. |
| /var/opt/senzing   | read-write | read-write | Configured by cloudformation template. |

## Details

### Network traffic for socketio

Using
[wireshark](https://www.wireshark.org/)
it is seen that the network traffic for XTerm is protected by TLSv1.2
and network traffic for SSH is protected by SSH

![Traffic from XTerm to host](xterm-to-host.png)

![Traffic from host back to XTerm](host-to-xterm.png)

![SSH traffic](sshd.png)
