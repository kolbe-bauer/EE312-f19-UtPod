//
// Created by Kolbe on 10/24/2019.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "UtPod.h"

using namespace std;

UtPod::UtPod() {
    //this(MAX_MEMORY);
    //UtPod(MAX_MEMORY);
    memSize=MAX_MEMORY;
    songs= NULL;
    srand((unsigned)time(0));
}
UtPod::UtPod(int size) {
    if(size>MAX_MEMORY||size<=0)
        memSize=MAX_MEMORY;
    else
        memSize=size;
    songs= NULL;
    srand((unsigned)time(0));
}
int UtPod::removeSong(Song const &s) {
    if(songs->s==s){
        songs=songs->next;
        return SUCCESS;
    }
    SongNode *prev=songs;
    SongNode *current=songs->next;
    while (current!= NULL){
        Song search=current->s;
        if(search==s){
            prev->next=current->next;
            return SUCCESS;
        }
        prev=current;
        current=current->next;
    }
    return NOT_FOUND;
}
int UtPod::addSong(Song const &s) {
    if(getRemainingMemory()-s.getSize()<0){
        return NO_MEMORY;
    }
    SongNode* node = new struct SongNode;
    //cout << "starting node size" << node->s.getSize() << endl;
    //cout << "starting song passed size " << s.getSize() << endl;
    node->s=s;
    //cout << "new node size " << node->s.getSize() << endl;
    //cout << "starting next node " << node->next << endl;
    //cout << "starting song ptr " << songs << endl;
    node->next=songs;
    //cout << "new next node " << node->next << endl;
    songs=node;
    //cout << "new song ptr " << songs << endl;
    return SUCCESS;
}
void UtPod::clearMemory() {
    SongNode* ptr=songs;
    while (ptr!=NULL){
        songs=songs->next;
        delete (ptr);
        ptr=songs;
    }
}
int UtPod::memUsed() {
    int amount=0;
    SongNode* ptr=songs;
    while(ptr!= NULL){
        amount=amount+ptr->s.getSize();
        //cout << "new amount " << amount << endl;
        ptr=ptr->next;
    }
    return amount;
}
int UtPod::getRemainingMemory() {return getTotalMemory()-memUsed();}
void UtPod::showSongList() {
    if(songs==NULL){
        cout << "Empty UtPod" << endl;
        return;
    }
    cout << "Your Songs Are: " << endl;
    SongNode* ptr=songs;
    while(ptr!=NULL){
        Song s=ptr->s;
        cout << s << endl;
        ptr=ptr->next;
    }
}
void UtPod::shuffle() {
    for(int i =0; i< numSongs()*3;i++)
    {
        int index1= rand()%numSongs();
        int index2= rand()%numSongs();
        SongNode* cur1=songs;
        SongNode* cur2=songs;
        for(int x=0;x<index1;x++)
            cur1=cur1->next;
         for(int x=0;x<index2;x++)
            cur2=cur2->next;
        swapSongs(cur1,cur2);
    }
}
void UtPod::sortSongList() {
    /*if(songs==NULL)
        return;
    bool swapped=false;
    SongNode* cur=songs;
    SongNode* last=NULL;
    do{
        swapped=false;
        cur=songs;
        while(cur->next != last){
            if(cur->s > cur->next->s){
                swapSongs(cur, cur->next);
                swapped=true;
            }
            cur=cur->next;
        }
        last=cur;
    }while(swapped);
    */

    SongNode* cur=songs;
    while (cur!=NULL){
        SongNode* highest=cur;
        SongNode* ptr=cur->next;
        while (ptr!=NULL){
            if(ptr->s < highest->s)
                highest=ptr;
            ptr=ptr->next;
        }
        if(highest!=cur)
            swapSongs(cur,highest);
        cur=cur->next;
    }
}
void UtPod::swapSongs(UtPod::SongNode *node1, UtPod::SongNode *node2) {
    Song temp=node1->s;
    node1->s=node2->s;
    node2->s=temp;
}
int UtPod::numSongs() {
    int count=0;
    SongNode* ptr=songs;
    while(ptr!= NULL){
       count+=1;
       ptr=ptr->next;
    }
    return count;
}
UtPod::~UtPod() {
    clearMemory();
}