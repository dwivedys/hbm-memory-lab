
## Read data into target buffer from variables
    - fgets - read from source (any file pointer or stdin) into a char buffer limited to the size of the target buffer. Includes the \n in the target buffer  
    - strncpy - read data into target buffer from source limited to size of target. Doesnt null terminate. No formatting of the target buffer  
    - snprintf - read data into target buffer from source variables formatted. Always null terminates the target buffer
### Why snprintf over sprintf
    - sprintf assumes the destination buffer is large enough, making it highly vulnerable to buffer overflow attacks. 
    - snprintf requires you to specify the buffer size, ensuring your application remains secure against memory corruption.

## Read data into target variables from buffer 
 - sscanf - read data from buffer into target vars in a formatted manner; simple scanf reads from stdin into variables

## Write data to file 
- fprintf - write data to file (via file pointer) from source variables formatted 
