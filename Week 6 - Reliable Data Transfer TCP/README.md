## Lab Activity 1
1. What is the IP address and TCP port number used by the client computer (source) that is transferring the alice.txt file to gaia.cs.umass.edu? To answer this question, it’s probably easiest to select an HTTP message and explore the details of the TCP packet used to carry this HTTP message, using the “details of the selected packet header window.”
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/ce865efc-e379-4e31-82ab-6fd6aef242fa)

2. What is the IP address of gaia.cs.umass.edu? On what port number is it sending and receiving TCP segments for this connection?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8a7bc939-1b64-40d2-8f5f-fd31759795a0)

3. What is the sequence number of the TCP SYN segment that is used to initiate the TCP connection between the client computer and gaia.cs.umass.edu? (Note: this is the “raw” sequence number carried in the TCP segment itself; it is NOT the packet # in the “No.” column in the Wireshark window. Remember there is no such thing as a “packet number” in TCP or UDP; as you know, there are sequence numbers in TCP and that’s what we’re after here. Also note that this is not the relative sequence number with respect to the starting sequence number of this TCP session.). What is it in this TCP segment that identifies the segment as a SYN segment?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/c6b4e690-003d-47a5-a039-1a9032bbf7a1)

4. What is the sequence number of the SYNACK segment sent by gaia.cs.umass.edu to the client computer in reply to the SYN? What is it in the segment that identifies the segment as a SYNACK segment? What is the value of the Acknowledgement field in the SYNACK segment? How did gaia.cs.umass.edu determine that value?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/08e47a1c-002c-4d71-acb7-da2e6e5138f7)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/fba56165-2587-4edb-a4da-3c285f80c1d3)

5. What is the sequence number of the TCP segment containing the header of the HTTP POST command? Note that in order to find the POST message header, you’ll need to dig into the packet content field at the bottom of the Wireshark window, looking for a segment with the ASCII text “POST” within its DATA field1,2 . How many bytes of data are contained in the payload (data) field of this TCP segment? Did all of the data in the transferred file alice.txt fit into this single segment?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/6d05ef1e-07e7-4aad-a487-9882c289af91)

6. What is the length (header plus payload) of the segment that contains POST?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/a3a8b5c5-f7b5-43fe-bb10-db5268741885)

7. How many retransmitted segments are there? What did you check in order to answer this question?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/552889b9-d38d-4275-bea9-94cabdd7fbfe)


## Lab Activity 2
Consider the TCP segment containing the HTTP “POST” as the first segment in the data transfer part of the TCP connection.
1. At what time was the first segment (the one containing the HTTP POST) in the datatransfer part of the TCP connection sent?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/b19c1918-e3d5-4282-b541-678f5f28431a)
2. At what time was the ACK for this first data-containing segment received?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/10aa1d49-ac29-403c-afc3-e8564824c4b1)
3. What is the RTT for this first data-containing segment?
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/9a2f33d2-dc5d-413f-bc45-f2d08ebe3b84)
4. What is the RTT value the second data-carrying TCP segment and its ACK? Second Segment
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/e9b6d8ae-5ce2-41a9-bebb-f9a2d3958950)

5. What is the EstimatedRTT value after the ACK for the second data carrying segment is received? Assume that in making this calculation after the received of the ACK for the second segment, that the initial value of EstimatedRTT is equal to the measured RTT for the first segment, and then is computed using the EstimatedRTT equation (page 236 of the attached PDF file in elok), and a value of **α** = 0.12
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/6d21f2d1-b448-43b9-a260-db596a1262be)

## Assignment
1.  Read how to calculate Estimated RTT from the supplementary material in Elok. Count Estimated RTT up to the last TCP segment that contains the data in the tracefile. Similar with Activity 6.2, the first TCP segment is the first segment that contains data (ignore the segments involved in the three-way handshake). Plot the graphic showing the relationship between Sample RTT and Estimated RTT as shown in Figure 3.32 in the supplementary material. *Use alpha=0.125
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/6d4158ea-cde5-4fb2-bf22-a28954b8ab0f)

![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/580dba3d-90b0-4071-afde-cdeebd4ba490)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8cf15aaf-9573-4adc-8150-ffb0bd57a40a)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/0fe94822-15d2-4c3a-92e6-0330aa099cd1)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/c7cefaf3-40c5-4d37-98bc-fa70c7692b63)

2. Read how to calculate the timeout in the supplement material and plot the timeout value on the same graph as the graph from number 2. Analyze the graph you get and see if there are segments that are timed out based on the timeout calculation? If so, what segment/packet number? Assume the timeout values for the first and second segments are 1s (1,000ms). After the ACK for the second segment is received, the timeout value is calculated according to the formula on page 237 of the supplement material and is set as the timeout for the third segment and so on. *Use beta=0.25.
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8190d691-ad0f-4b76-a9b8-9d31f80f3689)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/03c22519-3924-4939-9e54-522d0db61811)
![image](https://github.com/ramzyizza/Computer-System-and-Networking-Lab/assets/89899122/8039dce6-1f31-4c4e-8f74-7c4032844243)
