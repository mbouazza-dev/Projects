
### LocalKube-APIs

**written with Java, SpringBoot, JUnit5**

# LocalKube
The purpose of the LocalKube application is to enable the deployment and control of applications written in Java inside _docker_ containers. 

The application is composed of:

 - REST services to control the applications deployed by a user
 - REST services allowing discussion between LocalKube and deployed applications
 - a _client_ library named local-kube-api which is added in each container. It is accessible by each deployed application and can chat with REST services between LocalKube and the deployed applications.

## Features

- Application deployment and monitoring by creating a docker container around an application and then starting an instance of the docker container. 
- Management of all launched docker container instances, i.e. listing the running instances and the possibility to stop them.  
- Gather all the logs of each application in all the instances of the Docker Containers and be able to display a filtered view of the logs.
- Start and stop an auto-scale service that ensures that the number of running instances of an application remains constant and deletes or starts new instances.

## Prerequisite
1.  Install Docker
	- Linux [Docker for Linux](https://docs.docker.com/engine/install/)
    - Mac [Docker for Mac](https://docs.docker.com/docker-for-mac/install/)
    - Windows [Docker for Windows](https://docs.docker.com/docker-for-windows/install/)
2.  Install the latest version of Java JDK [manually](https://www.mozilla.org/fr/firefox/new/)
    - Windows [JDK-Windows](https://docs.oracle.com/en/java/javase/15/install/installation-jdk-microsoft-windows-platforms.html#GUID-A7E27B90-A28D-4237-9383-A58B416071CA)
 3. A web browser (We recommend [Firefox](https://docs.oracle.com/en/java/javase/15/install/installation-jdk-microsoft-windows-platforms.html#GUID-A7E27B90-A28D-4237-9383-A58B416071CA))
3. A tool for sending requests (Curl, Postman....)

Translated with www.DeepL.com/Translator (free version)

## Launch LocalKube

The LocalKube application is delivered as a *.jar* executable.
Simply go to the directory containing your applications, place *localkube.jar* in it and double-click on it or launch it with the command :

    java - jar local-kube-api.jar

## Launch an application
To launch an application, the *.jar* of the corresponding application must be in the /jars directory at the root of the execution directory.

The launch is done by sending a JSON to the address `http://localhost:8080/localkube.app/start` containing the name of the application and a Port number:

       {
               "name": "todomvc:8081"
       }

(A more or less long waiting time may appear depending on the resources available on your machine).

Once the application is launched in a Container on the host machine, you receive information about the application

    {
          "id": 1,
          "name": "helloworld:1000",
          "dockerPort": 1000,
          "servicePort": 15001,
          "dockerInstance": "helloworld0"
    }

However, if you specified an application name not present in the jars/ folder then you will receive a JSON error file of the type:

    {
          "id": 0,
          "name": "Error",
          "dockerPort": 0,
          "servicePort": 0,
          "dockerInstance": "Failed to load the application"
    }

In this case check that you have entered the correct name without spelling mistakes, and/or that the .jar file is present in the jars/ folder.

# List the instances
You can access the list of current instances by visiting:
(Note: you can only see the containers that are still active, the ones that are not active anymore are not visible anymore by the API)
   

     localhost:8080/localkube.app/list

Result:

    [
              {
               "id": 201,
               ...
              },
              {
               "id": 202,
               ...
              },
              {
               "id": 203,
               ...
              }
    ]

## Stop an instance

The stop of an instance present in a container is done by sending a JSON to `http://localhost:8080/localkube.app/stop` containing only the instance id:

    {
           "id": 201
    }

Once the application is stopped on the host machine, you receive information about the application and its execution time:

    {
             "id": 201,
             "app": "todomvc:8081",
             "port": 8081,
             "service-port": 15201,
             "docker-instance": "todomvc-12",
             "elapsed-time": "4m37s"
    } 

    

However, if you specify an incorrect or non-existent application id then you will receive a JSON error file of the type:

    {
          "id": 0,
          "name": "Error",
          "dockerPort": 0,
          "servicePort": 0,
          "dockerInstance": "Failed to stop the application"
    }


In this case check that you entered the correct id, or that the instance you are trying to stop is not already stopped.

## Get the list of logs

You can view the list of logs (potential error message from application contained in a container) of all containers by visiting:

    localhost:8080/log/logs

To get the logs created from a certain date 

    localhost:8080/localkube.logs/:time

Or :time is a date argument representing all logs from the last _time_ minutes. 
The format of :time is the following: "year-month-day hour:minutes:seconds" (beware quotes are required). 

Result:

    [
           {
             "id": 201,
             "app": "todomvc:8081",
             "port": 8081,
             "service-port": 15201,
             "docker-instance": "todomvc-12",
             "message": "ceci est un message de log",
             "timestamp": "2019-10-15T23:58:00.000Z"
           },
           {
             "id": 202,
             "app": "todomvc:8082",
             "port": 8082,
             "service-port": 15202,
             "docker-instance": "todomvc-13",
             "message": "ceci est un message de log",
             "timestamp": "2019-10-15T23:58:45.000Z"
           },
           {
             "id": 203,
             "app": "demo:8083",
             "port": 8083,
             "service-port": 15203,
             "docker-instance": "demo-2",
             "message": "demo d'un message de log",
             "timestamp": "2019-10-15T23:59:34.000Z"
           }
    ]

Log filtering is also available via the endpoint:

    localhost:8080/localkube.logs/:time/:filter

The value :filter here can be an integer corresponding to an id or a string corresponding to an application name.

The available filters are:
- byId -> Returns the logs of the _:time_ last minutes of the application with the id _:filter_.
- byApp -> Returns logs of the last _:time_ minutes for the application with the name _:filter_.
- byInstance -> Returns the logs for the application having an id, name or docker instance corresponding to _:filter_.
