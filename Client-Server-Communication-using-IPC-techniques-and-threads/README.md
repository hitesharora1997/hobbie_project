# Client-Server-Communication-using-IPC-techniques-and-Threads
This project is use to establish the connection between requesting client, processing client  and the server



        ◦ This project is use to establish the connection between requesting client, processing client  and the server. The server will accept the request from one of the many requesting clients and will send it to the appropriate processing client, then the processing client will  perform the operation and will send back the result to the server and at last the server will  send this result to that particular requesting client.
            ▪ To establish the connection between server and clients there are some system calls in IPC.
            ▪ FIFOs : Used to send request (addition, subtraction and multiplication operation) of requesting clients to server
            ▪ Pipe: used to forward request from server to the appropriate processing clients to process  data of the requesting clients by creating threads
            ▪ Shared Memory : used to write processed data to server back from processing clients, synchronization is achieved by using thread semaphores.
            ▪ Message Queues: used by server to send data to requesting clients
