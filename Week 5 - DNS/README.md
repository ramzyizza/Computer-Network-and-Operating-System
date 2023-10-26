
## Lab Activity 1
1. Run nslookup to obtain the IP address of the web server for the Indian Institute of Technology in Bombay, India: www.iitb.ac.in. What is the IP address of www.iitb.ac.in
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/1906828e-947b-4e06-854e-b4edd2917b62)

2. What is the IP address of the DNS server that provided the answer to your nslookup command in question 1 above?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/6b5f52f9-0047-4ea8-96e5-d0e697144f52)

4. Did the answer to your nslookup command in question 1 above come from an authoritative or non-authoritative server?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/367fc91b-ab2f-408e-bc06-9260eaf06647)

5. Use the nslookup command to determine the name of the authoritative name server for the iit.ac.in domain. What is that name? (If there are more than one authoritative servers, what is the name of the first authoritative server returned by nslookup)? If you had to find the IP address of that authoritative name server, how would you do so?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/3184958a-49f8-4e90-8ba0-03e9e771362f)

## Lab Activity 2
1. Locate the first DNS query message resolving the name writing.engr.psu.edu. What is the packet number3 in the trace for the DNS query message? Is this query message sent over UDP or TCP?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8aae55dd-5689-4a12-8b6b-363c29464bf0)

2. Now locate the corresponding DNS response to the initial DNS query. What is the packet number in the trace for the DNS response message? Is this response message received via UDP or TCP?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/c373b5d9-df87-4f3b-8a33-ba3ffdfa344d)

3. What is the destination port for the DNS query message? What is the source port of the DNS response message?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/f1849be1-2d24-48c9-aed1-deac5753e1ca)

4. What is the destination port for the DNS query message? What is the source port of the DNS response message?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/0c36f833-8c5a-4893-adca-c0b09f67e364)

5. Examine the DNS query message. How many “questions” does this DNS message contain? How many “answers” answers does it contain?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/a86b2d12-6796-4a94-b423-5540e343cf3f)

6. Examine the DNS response message to the initial query message. How many “questions” does this DNS message contain? How many “answers” answers does it contain?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/ba4ce76f-515e-46e0-9326-cd97f85a2e46)

## Lab Activity 3
1. What is the destination port for the DNS query message? What is the source port of the DNS response message?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/b65c3cd9-7f7b-430e-8f3d-e6ff84931a1b)

2. To what IP address is the DNS query message sent? Is this the IP address of your default local DNS server?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8a1244e3-65f0-4f13-8f00-6d9fcddcc0ea)

3. Examine the DNS query message. What “Type” of DNS query is it? Does the query message contain any “answers”?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/3abc31cd-41fc-497d-bc2e-42bb4a05eb79)

4. Examine the DNS response message to the query message. How many “questions” does this DNS response message contain? How many “answers”?
  
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/151bd856-c1cf-4573-9d37-962e1dabbb4d)

7. To what IP address is the DNS query message sent? Is this the IP address of your default local DNS server?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/1826dd88-848f-4b26-9f6f-85473ad46de1)

8. Examine the DNS query message. How many questions does the query have? Does the query message contain any “answers”?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/4aa2da7a-bef1-44dc-9314-9ced00a6b5f1)

9. Examine the DNS response message. How many answers does the response have? What information is contained in the answers? How many additional resource records are returned? What additional information is included in these additional resource records?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/453f86a4-ed03-4a3d-92f3-2f890992e5a9)

## Assignment
1. Find out how to run nslookup on Windows cmd (or the OS your PC is using). Then perform a iterative query manually to resolve dcse.fmipa.ugm.ac.id so that the IP address can be known without contacting the local DNS server.
a. Show any step-by-step command you entered and the output (screenshot)

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/3d835c3a-b9cf-41ba-983b-82656cba4cbf)	![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/77e79e3e-856f-45f9-a6fc-eabfc60c42c4)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/1355aff8-68e7-48b0-accc-fa68e4a39383)

b. In total, how many name servers did you visit? Also show the IP addresses of these servers.
	![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/c1fdf39b-e04c-4cbb-bbad-4528a5832963)
