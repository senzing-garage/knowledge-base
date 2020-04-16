# How to install Tiller

## Overview

Instructions for installing the Tiller portion of [Helm](https://helm.sh).

### Contents

1. [Install on Kubernetes](#install-on-kubernetes)
    1. [CentOS](#centos)
    1. [Ubuntu](#ubuntu)
    1. [macOS](#macos)
    1. [Windows](#windows)
1. [Test](#test)
1. [Troubleshooting](#troubleshooting)
1. [References](#references)

## Install on Kubernetes

### CentOS

### Ubuntu

1. Create a file named *clusterrole.yaml*. Example:

    ```yaml
    apiVersion: rbac.authorization.k8s.io/v1
    kind: ClusterRole
    metadata:
      annotations:
        rbac.authorization.kubernetes.io/autoupdate: "true"
      labels:
        kubernetes.io/bootstrapping: rbac-defaults
      name: cluster-admin
    rules:
    - apiGroups:
      - '*'
      resources:
      - '*'
      verbs:
      - '*'
    - nonResourceURLs:
      - '*'
      verbs:
      - '*'
    ```

1. Create role.

    ```console
    kubectl create -f clusterrole.yaml
    ```

1. Create ServiceAccount and bind to ClusterRole.

    ```console
    kubectl create serviceaccount -n kube-system tiller
    kubectl create clusterrolebinding tiller-cluster-rule \
      --clusterrole=cluster-admin \
      --serviceaccount=kube-system:tiller
    ```

1. Initialize or update Tiller.

    Initialize:

    ```console
    helm init --service-account tiller
    ```

    Update:

    ```console
    helm init --upgrade --service-account tiller
    ```

### macOS

### Windows

## Install on Minishift

1. [Deploy Helm Charts on Minishift’s OpenShift for Local Development](https://blog.openshift.com/deploy-helm-charts-minishifts-openshift-local-development/)
1. [Helm Add-on](https://github.com/minishift/minishift-addons/tree/master/add-ons/helm)

1. XXX
   Example:

    ```console
    minishift addons install --defaults
    minishift addons enable admin-user
    ```

1. XXX
   Example:

    ```console
    cd /tmp
    git clone https://github.com/jorgemoralespou/minishift-addons
    cd minishift-addons
    minishift addons install helm
    minishift addons apply helm
    ```

## Test

1. Test

    ```console
    kubectl --namespace kube-system get pods | grep tiller
    ```

## Troubleshooting

## References

1. [Step 4: Install and configure Helm and Tiller](https://docs.bitnami.com/kubernetes/get-started-kubernetes/#step-4-install-and-configure-helm-and-tiller)
