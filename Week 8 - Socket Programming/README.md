# EchoServer and EchoClient Documentation

### Overview:
The `EchoServer` and `EchoClient` classes demonstrate basic server-client communication using Java's socket programming. The server accepts connections and echoes back messages with a "Hello" prefix. The client sends user input and receives the server's response.

### EchoServer:

**Functionality:**
- Listens for client connections on a specific port.
- Accepts incoming client connections and establishes a communication stream.
- Reads a message received from the client.
- Prepends the received message with "Hello " and sends it back.

**Error Handling:**
- Catches and prints any exceptions that occur during the execution (like IO failures).

### EchoClient:

**Functionality:**
- Connects to the server using the server's IP address and port.
- Takes user input from the console.
- Sends the input to the server.
- Receives a response from the server and prints it to the console.
- Closes the connection after the communication.

**Error Handling:**
- Catches and prints any exceptions that occur during the execution.

### Communication Flow:
1. Server starts and waits for client connections.
2. Client connects, and the server acknowledges the connection.
3. Client sends a message (user's name) to the server.
4. Server receives the message, modifies it, and sends it back to the client.
5. Client receives the modified message and prints it.
6. The connection is terminated after the exchange.

### Usage:
- The server must be started before the client.
- The client requires user input for the message to be sent.
- Both programs should be executed on machines that are network-accessible to each other.

### Code Maintenance:
- Developers can modify the port number, the server's IP in the client class, and the response message in the server class.
- Error handling sections can be enhanced for more specific feedback.
