ARG JETTY_VERSION
FROM jetty:${JETTY_VERSION}

LABEL maintainer="Melon Bao <melon.bao@outlook.com>"

#ENV JAVA_OPTIONS=-agentlib:jdwp=transport=dt_socket,address=8000,server=y,suspend=n
ADD ./start.d/start.ini /var/lib/jetty/start.d

EXPOSE 8080

#ENTRYPOINT ["java","-Xdebug","-Xrunjdwp:transport=dt_socket,address=8000,server=y,suspend=n","-jar","/usr/local/jetty/start.jar"]

#ENTRYPOINT ["java","-agentlib:jdwp=transport=dt_socket,address=8000,server=y,suspend=n","-jar","/usr/local/jetty/start.jar"]

