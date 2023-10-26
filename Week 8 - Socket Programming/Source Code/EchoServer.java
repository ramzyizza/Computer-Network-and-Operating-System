import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class EchoServer {
    public static void main(String[] args){
        try {
            System.out.println("Waiting for clients...");
            ServerSocket ss = new ServerSocket(9806);
            Socket soc = ss.accept();
            System.out.println("Connection established");
            BufferedReader in = new BufferedReader(new InputStreamReader(soc.getInputStream()));
            String str = in.readLine();
            PrintWriter out = new PrintWriter(soc.getOutputStream(), true);
            out.println("Hello " + str);
            ss.close();
        }
        
        catch(Exception e){
            e.printStackTrace();
        }
    }
}
