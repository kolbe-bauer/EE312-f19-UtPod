//
// Created by Kolbe on 10/22/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "UtPod.h"
#include <ctime>


    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod::UtPod(){
        this(MAX_MEMORY);
    }

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod::UtPod(int size){
        if(size>MAX_MEMORY||size<=0)
            memSize=MAX_MEMORY;
        else
            memSize=size;
        memUsed=0;
        songs=nullptr;
        numSongs=0;
        srand((unsigned)time(0));
    }

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns a 0 if successful
         o returns -1 if not enough memory to add the song

     precondition: s is a valid Song
     input parms -

     output parms -
    */
    int UtPod::addSong(Song const &s){
        if(memUsed+*s.getSize()>memSize){
            return -1;
        }
        memUsed+=*s.getSize();
        SongNode node=new SongNode;
        node.s=*s;
        node.next=songs;
        songs=&node;
        numSongs++;
        return 0;
    }

    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns 0 if successful
         o returns -1 if nothing is removed
       input parms -

       output parms -
    */
    int UtPod::removeSong(Song const &s){
        if(numSongs=0)
            return -1;
        if(songs->s==s*){
            songs=songs->next;
            return 0;
        }
        SongNode *prev=songs;
        SongNode *current=songs->next;
        while (current!= nullptr){
            Song search=current->s;
            if(search==s*){
                prev->next=current->next;
                return 0;
            }
            prev=current;
            current=current->next;
        }
        return -1;
    }

    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */
    void UtPod::shuffle(){
        if(numSongs<=2)
            return;
        SongNode *head=nullptr;
        for(int i=0;i<numSongs;i++){
            int nextIndex=(int)(rand()%numSongs+1);//Math.random(numSongs-i);
            SongNode *current=songs;
            for(int j=0;j<nextIndex;j++){
                if(current==nullptr)
                    cout << "you dont messed up" << endl;
                current=current->next;
            }
            SongNode sNode=new SongNode;
            sNode.s=current->s;
            this->removeSong(&(current->s));
            s.next=head;
            head=s;
        }
        songs=head;
    }

    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms -

       output parms -
    */
    void UtPod::showSongList(){

    }

    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */
    void UtPod::sortSongList(){

    }

    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms -

       output parms -
    */
    void UtPod::clearMemory(){

    }

    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms -

       output parms -
    */
    int UtPod::getTotalMemory() {
        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms -

       output parms -
    */
    int UtPod::getRemainingMemory(){

    }

    ~UtPod();
}