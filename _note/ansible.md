---
title: Ansible
tags: Ansible
---

## Looping

### Array (with_items)

```yaml
vars:
  security_groups:
    - name: 'hello'
      desc: 'world'

    - name: 'hola'
      desc: 'mundo'

tasks:
  - name: Create required security groups
    ec2_group:
      name: "{{ item.name }}"
      description: "{{ item.desc }}"
    with_items: "{{ security_groups }}"
```

### Object (with_dict)

```yaml
tasks:
  - name: Print phone records
    debug: msg="User {{ item.key }} is {{ item.value.name }} ({{ item.value.telephone }})"
    with_dict: "{{ users }}"
```

## with_file

```yaml
- name: "Send key"
  ec2_key:
    key_material: "{{ item }}"
  with_file: ./keys/sshkey.pub

  # or
  with_fileglob: ./keys/*.pub
```

### Conditionals

```yml
- include: setup-debian.yml
  when: ansible_os_family == 'Debian'

  when: (ansible_distribution == "CentOS" and ansible_distribution_major_version == "6") or
        (ansible_distribution == "Debian" and ansible_distribution_major_version == "7")


  # Just like "and"
  when:
    - ansible_distribution == "CentOS"
    - ansible_distribution_major_version == "6"
```

## Expressions

```
{{ item }}
{{ item.name }}
{{ item[0].name }}

{{ item | default('latest') }}
```

## Includes

```
tasks:
  - include: wordpress.yml
    vars:
      wp_user: timmy
```


{% raw %}

## Getting started

### Hosts

    $ sudo mkdir /etc/ansible
    $ sudo vim /etc/ansible/hosts

    [example]
    192.0.2.101
    192.0.2.102

### Running a playbook

    $ ansible-playbook playbook.yml

## Tasks

    - hosts: all
      user: root
      sudo: no
      vars:
        aaa: bbb
      tasks:
        - ...
      handlers:
        - ...

### Includes

    tasks:
      - include: db.yml
    handlers:
      - include: db.yml user=timmy

## Handlers

    handlers:
      - name: start apache2
        action: service name=apache2 state=started

    tasks:
      - name: install apache
        action: apt pkg=apache2 state=latest
        notify:
          - start apache2

## Vars

    - host: lol
      vars_files:
        - vars.yml
      vars:
        project_root: /etc/xyz
      tasks:
        - name: Create the SSH directory.
          file: state=directory path=${project_root}/home/.ssh/
          only_if: "$vm == 0"

## Roles

    - host: xxx
      roles:
        - db
        - { role:ruby, sudo_user:$user }
        - web

    # Uses:
    # roles/db/tasks/*.yml
    # roles/db/handlers/*.yml

### Task: Failures

    - name: my task
      command: ...
      register: result
      failed_when: "'FAILED' in result.stderr"

      ignore_errors: yes

      changed_when: "result.rc != 2"

### Env vars

    vars:
      local_home: "{{ lookup('env','HOME') }}"

## References

  * [Intro](http://www.ansibleworks.com/docs/intro_configuration.html)
  * [Modules](http://www.ansibleworks.com/docs/modules.html)

{% endraw %}

#### CoreOS部署容器

> - CoreOS is a minimal operating system that supports popular container systems out of the box. The operating system is designed to be operated in clusters. For example, it is engineered to be easy to boot via PXE and on most cloud providers.

> - CoreOS produces, maintains and utilizes open source software for Linux containers and distributed systems. Projects are designed to be composable and complement each other in order to run container-ready infrastructure.


> - CoreOS是个轻量级的操作系统，整合了多种开源软件来构建容器基础架构，或者说它就是一个为了运行容器而定制的操作系统

> - 相比普通的Linux发型版本，因为用途明确，所以对系统进行了大量的定制和裁剪，保证了容器运行环境的稳定和高效

> - 集成了分布式管理系统，可以轻松构建服务集群

> - 更新周期稳定，保证容器环境可以支持新的功能

> - 系统使用双分区交替更新，更新后的系统分区如果意外损坏，可以用未更新的分区启动，降低了系统更新故障导致无法启动系统的风险

#### 什么是Ansible
> - Ansible是一款部署应用/管理系统的IT自动化工具。
> - Ansible基于OpenSSH传输内容，安全性有一定保障。
> - Ansible使用YAML语法构建自动化部署的配置内容。

#### 为什么选择Ansible构建自动化部署
> - 易于上手，学习成本相对较低
> - 结构简单，无需配置代理(agent-less)
> - 去中心化，远端机器的控制访问基于OpenSSH验证
> - 模块化设计，可以使用[Python](https://www.python.org)开发扩展模块，自研门槛较低
