# Support-Ticket-Generator
Creating an IT Support Ticket System for an IT company. All tickets have a ticket priority attribute which is set when creating the ticket. The tickets are then sorted according to their priority using Priority Heaps.

This was a lab assignment given by Lab Instructor Ms. Praveen Kolli, in the course CMP305: Data Structures and Algorithms, taught by Dr. Ali Alshatnawi at the American University of Sharjah.

You are developing a Help Desk System for an IT company. All IT related issues must be reported with attributes priority (1 to 10:  10 highest to 1 least), description and arriving time. 

•	Implement a Ticket class with the following attributes. It should also implement comparison operators.
    Priority – 1 to 10, Description, Arriving time

In the main, write a menu that displays the below items:
New Ticket – Adds a ticket to the heap based on the priority. Generate arriving time of the ticket as provided.
Serve Ticket – Deletes the Ticket that is been served. Note that the highest priority ticket must be served first. Get the current time and display as processing time. 
Display Pending Tickets – Display all the tickets yet to be served. 
Exit
