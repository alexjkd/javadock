# Description

This is a project based on Laravdock which is a serials of devtools for PHP to use Larval, you can. get reference by following url

https://laradock.io/

# Docker compose  commands for container

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

  



# Tomcat

* Folders

> 'conf', 'webapps','lib': folders in container which have been mapped outside
>
> 'webapps_2': folder in container which has been mapped to 'webapps' in this project 

* Access URL

> http://localhost:8081/ : This is URL for original pages in tomcat with managment enabled.
>
> http://localhost:8080: this is the URL for the application in the folder of 'webapps' in this project

# Jetty

* Folders

> 'start.d': saved debugging  configuration which has been copied to container while building the container

# Mysql

* db data

> All db data has been saved to ~/.javadock/data/mysql

# Logs

* Mysql, tomcat

> the logs in container have been mapped to 'logs' folder of this project

