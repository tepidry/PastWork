/**
 * MessageQueue.java
 * 
 * This program implements the Channel interface 
 * such that the send() and receive() methods
 * are blocking
 *
 * @author Gagne, Galvin, Silberschatz
 * Operating System Concepts with Java - Eighth Edition
 * Copyright John Wiley & Sons - 2010.
 * 
 */

@SuppressWarnings("unchecked")

public class MessageQueue<E> implements Channel<E>
{
    private E elements[];	// array to store elements
    private int size;		// the size of the array
    private int count;		// number of elements in the buffer
    private int in, out;	// position in the array to insert and remove elements
    
    public static final int DEFAULT_SIZE = 3;

    public MessageQueue() {
        this(DEFAULT_SIZE);
    }
    
   public MessageQueue(int size) {
    if (size < 0)
        throw new IllegalArgumentException();
        
      this.size = size;
      elements = (E[]) new Object[size];
   }
   
   /*
    * This implements a blocking send
    */
   public synchronized void send(E item) {
        while (count == size) {
            try {
                wait();
            }
            catch (InterruptedException ie) { }
        }
        
        // there is room in the buffer!
        
        ++count;
        elements[in] = item;
        in = (in + 1) % size;
        
        // notify any waiting consumer(s)
        notify();
   }
   
   /*
    * This implements a  blocking receive
    */
    
   public synchronized E receive() {
        while (count == 0) {
            try {
                wait();
            }
            catch (InterruptedException ie) { }
        }
        
        --count;
        E item = elements[out];
        out = (out + 1) % size;
        
        // notify any waiting producer(s)
        notify();
        
        return item;
    }
}
