
## Lab Activity 1
1. Create a sleep process and send a SIGSTOP signal to put this process into stopped state. Take a screenshot that shows that this process is now in the stopped state (T). Hint: Use -- help to see how to use the kill command.
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/5f31d03c-71de-4ad5-a312-dd640e989022)

2. Send a SIGCONT signal to the stopped sleep process. Take a screenshot that shows that this process is no longer in the stopped state.
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/9165ea6e-a45d-48bf-9ed8-2800cb0d7541)


## Lab Activity 2

1. Modify the wait.c by putting the wait() function after the sleep() function. Compile and run the result in the background. Take some screenshots. 2. Take a screenshot of the process table. What happens with the child process?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/06706fad-219e-44c6-8070-57c2618633c9)

2. Take a screenshot of the process table. What happens with the child process?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/626e62fc-01c0-4fbd-926a-9494ab958031)

## Assignment
1. Create a program X that runs an arbitrarily large finite amount of loop. Run the program and print the process table using ps. What is the state of the process X during execution? Send a signal to stop and continue process X. How does the state of process X change? Explain with some screenshots of this process!

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/e1e99fe7-5ac2-4f99-8381-2ab91bb86c5f)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/9fa2a7aa-ebd0-4b87-ba7f-ff33654df262)

2. Create a program X that runs an arbitrarily large finite amount of loop. Run the program and print the process table using ps. What is the state of the process X during execution? Send a signal to stop and continue process X. How does the state of process X change? Explain with some screenshots of this process.

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/56ba15ef-eb90-4c78-ad8d-a6ae57531fa3)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/64614e31-0375-40e1-8c3c-ea70a2951957)
