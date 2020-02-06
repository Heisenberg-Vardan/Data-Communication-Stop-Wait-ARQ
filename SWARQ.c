#include<iostream>
#include<stdlib.h>
using namespace std;

string frame;         //initialization of variables required.
int sender[1000];     //sender array to confirm that a frame or message is sent
int receiver[1000];   //receiver array to confirm that a frame or message is received.
int t,st,rt,choice;   //t is the total transmission time.
int main()            //st is the sending time, rt is the receiving time.
{    int i=0;
     choice=1;        //choice indicates the user's needs.
     int j;
     while(choice==1)
     {
            start:
                cout<<"Enter the Message in accordance with the frame sequence\n" ;//user enters the message that is to be sent
                cin>>frame;
                st=rand()%12;       //we have used a random number generator.
                if (st<10)         //if st<10, the message is sent.
                {
                    cout<<"Message Sent in "<<st<<"secs"<<"\nWaiting for acknowledgement....\n"; //message is sent and is waiting for receiver to send acknowledgement.
                    rt=rand()%12;
                    sender[i]=1; //if the message is sent, sender[i] is set as 1.
                    if (rt<10)
                        {
                            cout<<"Acknowledgement recieved in "<<rt<<" secs"<<"\nTransmission complete!!!!!\n"; 
                            //acknowledgement received indicates that transmission has been successful.
                            t=st+rt; //total time taken is sending time + receiving time.
                            cout<<"Total Transmission Time taken is - "<<t<<" secs\n\n";
                            receiver[i]=1; //receiver[i]=1 indicates that receiver has received the message.
                            cout<<"Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n"; //asking the user for options
                            cin>>j;
                            if((j==0)&&(j!=1))
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
                            receiver[i]=0; //if the message is sent and receiver has not received the message, receiver[i] is 0. 
                            cout<<"Acknowledgement Lost... \n"<<"Enter 1 to enter new message\n"<<"Enter 2 to resend previous message\n"<<"Enter 3 to abort Transmission\n";
                            // if the acknowledgement is not received, transmission is not complete, so the user is asked if he wants to send the message again.
                            cin>>choice;
                            if(choice==2) //if the user wants to retransmit the previous message, it goes through this loop.
                            {
                                cout<<"previous frame is: "<<frame<<"\n";
                                cout<<"Retransmitting previous frame...\n";
                                st=rand()%12;
                                if (st<10)
                                {
                                    cout<<"Message Sent in "<<st<<"secs"<<"\nWaiting for acknowledgement....\n"; //same process as indicated above.
                                    rt=rand()%12;
                                    sender[i]=1;
                                    if (rt<10)
                                    {
                                        cout<<"Acknowledgement recieved in "<<rt<<"secs\n"<<"\nTransmission complete!!!!!\n"; 
                                        //now acknowledgement is received and the transmission is complete.
                                        t=st+rt;
                                        cout<<"Total Transmission Time taken is - "<<t<<" secs\n";
                                        receiver[i]=1;
                                        cout<<"Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n";
                                        cin>>j;
                                        if(j==0 && j!=1)
                                        {
                                            break;
                                        }
                                        else
                                        {
                                            goto start; // if the user wants to send another message, this label starts the process again.
                                        }

                            }

                        }

                }
                        }
                }
                else
                {           sender[i]=0; //if the sender could not send the data or the data was lost in between, it is indicated as sender[i]=0
                            cout<<"Data Lost \n"<<"Enter 1 to enter new message\n"<<"Enter 2 to resend previous message\n"<<"Enter 3 to abort Transmission\n";
                      //if the user wishes to send the previous message again, he has to press 2, for a new message he has to press 1, to exit press 0      
                            cin>>choice;
                            if(choice==2) // if user wishes to retransmit the previous message
                            {
                                cout<<"previous frame is: "<<frame<<"\n";
                                cout<<"Retransmitting previous frame...\n";
                                st=rand()%12;
                                if (st<10)
                                {
                                    cout<<"Message Sent in "<<st<<"secs"<<"\nWaiting for acknowledgement....\n";
                                    rt=rand()%12;
                                    sender[i]=1;  //the same procedure to resend the data is followed again.
                                    if (rt<10)
                                    {
                                        cout<<"Acknowledgement recieved in "<<rt<<"secs\n"<<"\nTransmission complete!!!!!\n";
                                        t=st+rt;
                                        cout<<"Total Transmission Time taken is - "<<t<<" secs\n";
                                        receiver[i]=1;
                                        cout<<"Enter 1 if you wish to send another frame\nEnter 0 if you wish to abort\n";
                                        cin>>j;
                                        if(j==0 && j!=1)
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
