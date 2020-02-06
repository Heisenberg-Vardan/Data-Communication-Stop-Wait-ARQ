#include&lt;iostream&gt;
#include&lt;stdlib.h&gt;
using namespace std;
string frame; //initialization of variables required.
int sender[1000]; //sender array to confirm that a frame or message is sent
int receiver[1000]; //receiver array to confirm that a frame or message is received.
int t,st,rt,choice; //t is the total transmission time.
int main() //st is the sending time, rt is the receiving time.
{ int i=0;
choice=1; //choice indicates the user&#39;s needs.
int j;
while(choice==1)
{
start:
cout&lt;&lt;&quot;Enter the Message in accordance with the frame sequence\n&quot; ;//user enters the message
that is to be sent
cin&gt;&gt;frame;
st=rand()%12; //we have used a random number generator.
if (st&lt;10) //if st&lt;10, the message is sent.
{
cout&lt;&lt;&quot;Message Sent in &quot;&lt;&lt;st&lt;&lt;&quot;secs&quot;&lt;&lt;&quot;\nWaiting for acknowledgement....\n&quot;; //message is
sent and is waiting for receiver to send acknowledgement.
rt=rand()%12;
sender[i]=1; //if the message is sent, sender[i] is set as 1.
if (rt&lt;10)
{
cout&lt;&lt;&quot;Acknowledgement recieved in &quot;&lt;&lt;rt&lt;&lt;&quot; secs&quot;&lt;&lt;&quot;\nTransmission complete!!!!!\n&quot;;
//acknowledgement received indicates that transmission has been successful.
t=st+rt; //total time taken is sending time + receiving time.
cout&lt;&lt;&quot;Total Transmission Time taken is - &quot;&lt;&lt;t&lt;&lt;&quot; secs\n\n&quot;;
receiver[i]=1; //receiver[i]=1 indicates that receiver has received the message.
cout&lt;&lt;&quot;Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n&quot;; //asking
the user for options
cin&gt;&gt;j;
if((j==0)&amp;&amp;(j!=1))
{
break;
}
else
{
goto start; //if the user presses 1, the process starts over again.
}
}
else
{

receiver[i]=0; //if the message is sent and receiver has not received the message, receiver[i]
is 0.
cout&lt;&lt;&quot;Acknowledgement Lost... \n&quot;&lt;&lt;&quot;Enter 1 to enter new message\n&quot;&lt;&lt;&quot;Enter 2 to
resend previous message\n&quot;&lt;&lt;&quot;Enter 3 to abort Transmission\n&quot;;
// if the acknowledgement is not received, transmission is not complete, so the user is
asked if he wants to send the message again.
cin&gt;&gt;choice;
if(choice==2) //if the user wants to retransmit the previous message, it goes through this
loop.
{
cout&lt;&lt;&quot;previous frame is: &quot;&lt;&lt;frame&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot;Retransmitting previous frame...\n&quot;;
st=rand()%12;
if (st&lt;10)
{
cout&lt;&lt;&quot;Message Sent in &quot;&lt;&lt;st&lt;&lt;&quot;secs&quot;&lt;&lt;&quot;\nWaiting for acknowledgement....\n&quot;;
//same process as indicated above.
rt=rand()%12;
sender[i]=1;
if (rt&lt;10)
{
cout&lt;&lt;&quot;Acknowledgement recieved in &quot;&lt;&lt;rt&lt;&lt;&quot;secs\n&quot;&lt;&lt;&quot;\nTransmission
complete!!!!!\n&quot;;
//now acknowledgement is received and the transmission is complete.
t=st+rt;
cout&lt;&lt;&quot;Total Transmission Time taken is - &quot;&lt;&lt;t&lt;&lt;&quot; secs\n&quot;;
receiver[i]=1;
cout&lt;&lt;&quot;Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n&quot;;
cin&gt;&gt;j;
if(j==0 &amp;&amp; j!=1)
{
break;
}
else
{
goto start; // if the user wants to send another message, this label starts the
process again.
}
}
}
}
}
}
else
{ sender[i]=0; //if the sender could not send the data or the data was lost in between, it is
indicated as sender[i]=0
cout&lt;&lt;&quot;Data Lost \n&quot;&lt;&lt;&quot;Enter 1 to enter new message\n&quot;&lt;&lt;&quot;Enter 2 to resend previous
message\n&quot;&lt;&lt;&quot;Enter 3 to abort Transmission\n&quot;;
//if the user wishes to send the previous message again, he has to press 2, for a new message he
has to press 1, to exit press 0
cin&gt;&gt;choice;

if(choice==2) // if user wishes to retransmit the previous message
{
cout&lt;&lt;&quot;previous frame is: &quot;&lt;&lt;frame&lt;&lt;&quot;\n&quot;;
cout&lt;&lt;&quot;Retransmitting previous frame...\n&quot;;
st=rand()%12;
if (st&lt;10)
{
cout&lt;&lt;&quot;Message Sent in &quot;&lt;&lt;st&lt;&lt;&quot;secs&quot;&lt;&lt;&quot;\nWaiting for acknowledgement....\n&quot;;
rt=rand()%12;
sender[i]=1; //the same procedure to resend the data is followed again.
if (rt&lt;10)
{
cout&lt;&lt;&quot;Acknowledgement recieved in &quot;&lt;&lt;rt&lt;&lt;&quot;secs\n&quot;&lt;&lt;&quot;\nTransmission
complete!!!!!\n&quot;;
t=st+rt;
cout&lt;&lt;&quot;Total Transmission Time taken is - &quot;&lt;&lt;t&lt;&lt;&quot; secs\n&quot;;
receiver[i]=1;
cout&lt;&lt;&quot;Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n&quot;;
cin&gt;&gt;j;
if(j==0 &amp;&amp; j!=1)
{
break; // if the user wishes to abort, this statement terminates the process here.
}
else
{
goto start;
}
}

}
}
}
}
return 0;
}