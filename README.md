# Description

This is a project based on Laravdock which is a serials of devtools for PHP to use Larval, you can. get reference by following url

https://laradock.io/

---

# Set configuration before start container

> please copy 'env-example' to '.env' in the project root to get configuration setting

# Github acceleration [useless?]

- Get IP address by 'https://www.ipaddress.com/' and update /etc/hosts

  > 192.30.253.113 github.com
  > 192.30.253.119 gist.github.com
  > 185.199.108.153 assets-cdn.github.com
  > 199.232.28.133 raw.githubusercontent.com
  > 199.232.28.133 gist.githubusercontent.com
  > 199.232.28.133 cloud.githubusercontent.com
  > 199.232.28.133 camo.githubusercontent.com
  > 199.232.28.133 avatars0.githubusercontent.com
  > 199.232.28.133 avatars1.githubusercontent.com
  > 199.232.28.133 avatars2.githubusercontent.com
  > 199.232.28.133 avatars3.githubusercontent.com
  > 199.232.28.133 avatars4.githubusercontent.com
  > 199.232.28.133 avatars5.githubusercontent.com
  > 199.232.28.133 avatars6.githubusercontent.com
  > 199.232.28.133 avatars7.githubusercontent.com
  > 199.232.28.133 avatars8.githubusercontent.com

# Docker hub acceleration

```json
{
  "experimental": false,
  "debug": true,
  "registry-mirrors": ["http://hub-mirror.c.163.com"]
}
```

# Docker compose commands for container

Please excute all commands in the root of the project

- Start the container

  ```bash
  docker-compose start {container-name}
  ```

  This command can start more containers followed by names

- Stop the container

  ```ba
  docker-compose stop {container-name}
  ```

- Rebuild docker after change the configuration

  ```bash
  docker-copose build --no-cache {container-name}
  ```

  Please note this command will destroy the contain and data which has been created.

- Refresh container with latest configuration

  ```bash
  docker-compose up -d {container-name}
  ```

- Get live log after running the container

  ```bash
  docker-compose logs -f {container-name}
  ```

- Scale the container

  ```bash
  docker-compose scale {container-name}=num
  ```

---

# Tomcat

- Folders

  > 'conf', 'webapps','lib': folders in container which have been mapped outside
  >
  > 'webapps_2': folder in container which has been mapped to 'webapps' in this project

- Access URL

  > http://localhost:8080: this is the URL for the application in the folder of 'webapps' in this project
  >
  > http://localhost:8081/ : This is URL for original pages in tomcat with managment enabled.

- enable debugging

  ```dockerfile
  #add jpda environmental variables for remote debugging
  ENV JPDA_ADDRESS="8000"
  ENV JPDA_TRANSPORT="dt_socket"

  EXPOSE 8080

  ENTRYPOINT ["catalina.sh", "jpda", "run"]
  ```

# Jetty

- Folders

  > 'start.d': saved debugging configuration which has been copied to container while building the container
  >
  > 'sample': This is a sample web application to test your settings. You can copy it to 'webapps' of this project after started 'Jetty' container

- enable debugging

  > start.d/start.ini

  ```ini
  #===========================================================
  # Configure JVM arguments.
  # If JVM args are include in an ini file then --exec is needed
  # to start a new JVM from start.jar with the extra args.
  # If you wish to avoid an extra JVM running, place JVM args
  # on the normal command line and do not use --exec
  #-----------------------------------------------------------
  --exec
  -Xdebug
  -agentlib:jdwp=transport=dt_socket,address=8000,server=y,suspend=n
  # -Xmx2000m
  # -Xmn512m
  # -XX:+UseConcMarkSweepGC
  # -XX:ParallelCMSThreads=2
  # -XX:+CMSClassUnloadingEnabled
  # -XX:+UseCMSCompactAtFullCollection
  # -XX:CMSInitiatingOccupancyFraction=80
  # -verbose:gc
  # -XX:+PrintGCDateStamps
  # -XX:+PrintGCTimeStamps
  # -XX:+PrintGCDetails
  # -XX:+PrintTenuringDistribution
  # -XX:+PrintCommandLineFlags
  # -XX:+DisableExplicitGC
  ```

# Mysql

- db data

  > All db data has been saved to ~/.javadock/data/mysql

# PhpMyadmin

* Access URL 

  > http://45.76.204.189:8181

* credential

  > Host: 			mysql
  >
  > Credential: 	root/root
  >
  > Business:	   default/secret

# Redis

- get management with Gui

  ```bash
  docker-compose start redis redis-webui
  ```

- to access the managment gui

  > http://localhost:9987

# Jenkins

- plugins need to be installed

  - selected recomanded packages

  - addtional packages need to be installed to support maven project

    > 1. [Maven Integration plugin](https://plugins.jenkins.io/maven-plugin)
    > 2. [Build Token Trigger Plugin](https://plugins.jenkins.io/build-token-trigger)

- get admin password

  ```bash
  docker-compose exec jenkins cat /var/jenkins_home/secrets/initialAdminPassword
  ```

- get root cli

  ```bash
  docker-compose exec --user root jenkins bash
  ```

- create admin user

  > http://localhost:8090/securityRealm/addUser

- restart the service

  > http://localhost:8090/restart

- configure security

  > http://localhost:8090/configureSecurity/

- trigger a build

  > 1. enable the user Auth Token in user settings (must login with user to access the page)
  >
  > 2. set trigger token in the job settings
  >
  > 3. send post request as following
  >
  >    ```bash
  >    curl -X POST http://melon:auth_token@45.76.204.189:8090/buildByToken/build?job=ci-demo&token=ci-demo-trigger
  >    ```
  >
  > 4. or access the url by browser
  >
  >    ```bash
  >    http://melon:auth_token@45.76.204.189:8090/buildByToken/build?job=ci-demo&token=ci-demo-trigger
  >    ```

- a link to get more reference

  > https://segmentfault.com/a/1190000018939447

- get system info

  > http://45.76.204.189:8090/systemInfo

- set time zone to China

  > JAVA_OPTS: "-Djava.awt.headless=true -Duser.timezone=\"Asia/Shanghai\""
  > Zookeeper

* should set anonymous read access in security settings

  >  Allow anonymous read access

# ZooKeeper

> Included into this project, if necessary you can try it out.

# Kafka

- check version

  ```bash
  docker exec kafka find / -name \*kafka_\* | head -1 | grep -o '\kafka[^\n]*'
  ```

* extend broker

  ```bash
  docker-compose scale kafka=4
  ```

  ps will show

  ```bash
  [root@hedy kafka-docker]# docker ps
  CONTAINER ID        IMAGE                    COMMAND                  CREATED             STATUS              PORTS                                                NAMES
  adf18015a95e        kafka-docker_kafka       "start-kafka.sh"         6 seconds ago       Up 3 seconds        0.0.0.0:32771->9092/tcp                              kafka-docker_kafka_2
  d7eb1a9c9c72        kafka-docker_kafka       "start-kafka.sh"         6 seconds ago       Up 3 seconds        0.0.0.0:32770->9092/tcp                              kafka-docker_kafka_4
  0dddf1728ebd        kafka-docker_kafka       "start-kafka.sh"         6 seconds ago       Up 4 seconds        0.0.0.0:32769->9092/tcp                              kafka-docker_kafka_3
  19bc31339915        wurstmeister/zookeeper   "/bin/sh -c '/usr/..."   23 minutes ago      Up 23 minutes       22/tcp, 2888/tcp, 3888/tcp, 0.0.0.0:2181->2181/tcp   kafka-docker_zookeeper_1
  11bbf5c6ebec        kafka-docker_kafka       "start-kafka.sh"         23 minutes ago      Up 23 minutes       0.0.0.0:32768->9092/tcp                              kafka-docker_kafka_1
  ```

- create a topic

  - Create

  ```bash
  docker exec kafka-docker_kafka_1 \
  kafka-topics.sh \
  --create --topic topic001 \
  --partitions 4 \
  --zookeeper zookeeper:2181 \
  --replication-factor 2
  ```

  - view

  ```bash
  [root@hedy kafka-docker]# docker exec kafka-docker_kafka_3 \
  > kafka-topics.sh \
  > --describe \
  > --topic topic001 \
  > --zookeeper zookeeper:2181
  Topic:topic001	PartitionCount:4	ReplicationFactor:2	Configs:
  	Topic: topic001	Partition: 0	Leader: 1002	Replicas: 1002,1003	Isr: 1002,1003
  	Topic: topic001	Partition: 1	Leader: 1003	Replicas: 1003,1004	Isr: 1003,1004
  	Topic: topic001	Partition: 2	Leader: 1004	Replicas: 1004,1001	Isr: 1004,1001
  	Topic: topic001	Partition: 3	Leader: 1001	Replicas: 1001,1002	Isr: 1001,1002
  ```

- consum messaging

  ```bash
  docker exec kafka-docker_kafka_2 \
  kafka-console-consumer.sh \
  --topic topic001 \
  --bootstrap-server kafka-docker_kafka_1:9092,kafka-docker_kafka_2:9092,kafka-docker_kafka_3:9092,kafka-docker_kafka_4:9092
  ```

* produce messaging

  ```bash
  docker exec -it kafka-docker_kafka_1 \
  kafka-console-producer.sh \
  --topic topic001 \
  --broker-list kafka-docker_kafka_1:9092,kafka-docker_kafka_2:9092,kafka-docker_kafka_3:9092,kafka-docker_kafka_4:9092
  ```

# Kafka Manager

https://blog.csdn.net/isea533/article/details/73727485

https://www.jianshu.com/p/6a592d558812

---

# Logs

- Mysql, tomcat

  > the logs in container have been mapped to 'logs' folder of this project

# Webapps

This folder will be created after started 'Jetty' container and it mapped to 'webbapps' to 'Jetty'
