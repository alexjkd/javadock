ARG TOMCAT_VERSION
FROM tomcat:${TOMCAT_VERSION}

LABEL maintainer="Melon Bao <melon.bao@outlook.com>"

ADD conf/tomcat-users.xml $CATALINA_HOME/conf/

ADD webapps/manager/META-INF/context.xml $CATALINA_HOME/webapps/manager/META-INF/

ADD lib/mysql-connector-java-8.0.19.jar $CATALINA_HOME/lib/

RUN mkdir $CATALINA_HOME/webapps/app

#add jpda environmental variables for remote debugging
ENV JPDA_ADDRESS="8000"
ENV JPDA_TRANSPORT="dt_socket"

EXPOSE 8080
