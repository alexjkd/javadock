# Description

This is a project based on Laravdock which is a serials of devtools for PHP to use Larval, you can. get reference by following url

https://laradock.io/

---

# Docker compose  commands for container

Please excute all commands in the root of the project

* Start the container

  ```ba
  docker-compose start container
  ```

  This command can start more containers followed by names

* Stop the container

  ```ba
  docker-compose stop container
  ```

* Rebuild docker after change the configuration

  ```bas
  docker-copose build --no-cache container
  ```

  Please note this command will destroy the contain and data which has been created. 

* Refresh container with latest configuration

  ```bash
  docker-compose up -d container
  ```

* Get live log after running the container

  ```bas
  docker-compose logs -f container
  ```


# Github acceleration [useless?]

* Get IP address  by 'https://www.ipaddress.com/' and update hosts

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
  "registry-mirrors": [
    "http://hub-mirror.c.163.com"
  ]
}
```





# Set configuration before start container

> please copy 'env-example' to '.env' in the project root to get configuration setting

---

# Tomcat

* Folders

  > 'conf', 'webapps','lib': folders in container which have been mapped outside
  >
  > 'webapps_2': folder in container which has been mapped to 'webapps' in this project 

* Access URL

  > http://localhost:8080: this is the URL for the application in the folder of 'webapps' in this project
  >
  > http://localhost:8081/ : This is URL for original pages in tomcat with managment enabled.

# Jetty

* Folders

  > 'start.d': saved debugging  configuration which has been copied to container while building the container
  >
  > 'sample': This is a sample web application to test your settings. You can copy it to 'webapps' of this project after started 'Jetty' container

# Mysql

* db data

  > All db data has been saved to ~/.javadock/data/mysql

# Redis

* get management with Gui

  ```ba
  docker-compose start redis redis-webui
  ```

* to access the managment gui

  > http://localhost:9987

# Jenkins

* get admin password

  ```bas
  docker-compose exec jenkins cat /var/jenkins_home/secrets/initialAdminPassword
  ```

* get root cli

  ```bash
  docker-compose exec --user root jenkins bash
  ```

* create admin user

  > http://localhost:8090/securityRealm/addUser

* restart the service

  > http://localhost:8090/restart

* configure security

  > http://localhost:8090/configureSecurity/

  

  ---

  # Logs

* Mysql, tomcat

  > the logs in container have been mapped to 'logs' folder of this project

# Webapps

This folder will be created after started 'Jetty' container and it mapped to 'webbapps' to 'Jetty'

