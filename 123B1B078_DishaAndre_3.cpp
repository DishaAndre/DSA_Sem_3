+/*Assignment no.- 3
Disha Andre
PRN: 123B1B078

In code:
1)Class playlist is declared.
2)Functions implemented:
                (1)Show song.
                (2)Play song.
                (3)Add song at beginning.
                (4)Add song at end.
                (5)Delete first song.
                (6)Delete last song.
                (7)Delete song by title.
                (8)Delete song by id.
                (9)Reverse the playlist.


*/

#include<iostream>
#include<stdlib.h>

using namespace std;

struct song{
    int song_id;
    float song_duration;
    string song_title, song_artist;
    song *nextsong;
};

class playlist{
    song *header;
    
    public:
    playlist(){
        header = NULL;
        return;
    }

    void show_song(song *p){
        cout << p->song_id << "\t" << p->song_title << "\t" << p->song_artist <<"\t" << p->song_duration << endl;
        return;
    }

    void play_song(){
        if(!header){
            cout << "No songs in playlist." << endl;
            return;
        }
        song *p = header;
        while(p){
            show_song(p);
            p = p->nextsong;
        }
        return;
    }
    void add_at_begin(string title, string artist, float dura){
        song *newsong = new song;
    
        newsong-> song_id= rand()%1000;
        newsong-> song_title = title;
        newsong-> song_artist = artist;
        newsong-> song_duration = dura;

        newsong -> nextsong = header;
        header = newsong;
        

        return;
    }
    void add_at_end(string title, string artist, float dura){
        song *newsong = new song;
        if(!newsong){
            return;
        }

        newsong->song_id = rand() % 1000; 
        newsong->song_title = title;
        newsong->song_artist = artist;
        newsong-> song_duration = dura;

        newsong->nextsong = NULL;

        if(header == NULL){
            header = newsong;
            return;
        }
        song *p = header;
        while(p->nextsong)
            p = p->nextsong;
        p->nextsong = newsong;
        return;
    }

    void del_first_song(){
        if(header == NULL){
            cout << "No songs to delete." << endl;
            return;
        }
        song *temp = header;
        header = header->nextsong;
        delete temp;
        cout << "First song deleted." << endl;
        return;
    }

    void del_last_song(){
        if(header == NULL){
            cout << "No songs to delete." << endl;
            return;
        }

        if(header->nextsong == NULL){
            delete header;
            header = NULL;
            cout << "Last song deleted." << endl;
            return;
        }

        song *temp = header;
        while(temp->nextsong->nextsong != NULL){
            temp = temp->nextsong;
        }
        delete temp->nextsong;
        temp->nextsong = NULL;
        cout << "Last song deleted." << endl;
        return;
    }

    void del_by_title(string title){
        if(header == NULL){
            cout << "No songs to delete." << endl;
            return;
        }

        if(header->song_title == title){
            song *temp = header;
            header = header->nextsong;
            delete temp;
            cout << "Song titled \"" << title << "\" deleted." << endl;
            return;
        }

        song *temp = header;
        song *previous = NULL;

        while(temp != NULL && temp->song_title != title){
            previous = temp;
            temp = temp->nextsong;
        }

        if(temp == NULL){
            cout << "Song having title " << title << " not found." << endl;
            return;
        }

        previous->nextsong = temp->nextsong;
        delete temp;
        cout << "Song having title " << title <<" deleted." << endl;
    }

    void del_by_id(int id){
        if(header == NULL){
            cout << "No songs to delete." << endl;
            return;
        }

        if(header->song_id == id){
            song *temp = header;
            header = header->nextsong;
            delete temp;
            cout << "Song with ID " << id << " deleted." << endl;
            return;
        }

        song *temp = header;
        song *previous = NULL;

        while(temp != NULL && temp->song_id != id){
            previous = temp;
            temp = temp->nextsong;
        }

        if(temp == NULL){
            cout << "Song with ID " << id << " not found." << endl;
            return;
        }

        previous->nextsong = temp->nextsong;
        delete temp;
        cout << "Song with ID " << id << " deleted." << endl;
    }

    void search_by_title(string title){
        if(header == NULL){
            cout << "No songs in playlist." << endl;
            return;
        }

        song *temp = header;

        while(temp != NULL){
            if(temp->song_title == title){
                cout << "Song found: ";
                show_song(temp);
                return;
            }
            temp = temp->nextsong;
        }

        cout << "Song having title " << title << " is not found." << endl;
    }

    void reverse_list(){
        song *previous = NULL, *current = header, *next = NULL;

        while(current != NULL){
            next = current->nextsong;
            current->nextsong = previous;
            previous = current;
            current = next;
        }
        header = previous;
        cout << "Playlist reversed." << endl;
        return;
    }

   
};

int main(){
    playlist l1;
    
    l1.add_at_begin("Rain", "abc", 4.6);
    l1.add_at_begin("School", "Ann",2.5);
    l1.add_at_end("Life", "Sam",5.25);
    l1.add_at_begin("Sun","Nimmy",1.25);
    l1.add_at_end("Those days", "Harry",8.6);
    
    cout << "Playlist:" << endl;
    l1.play_song();
    
    cout << "\nSearching for song with title School:" << endl;
    l1.search_by_title("School");
    cout << "\nSearching for song with title: Happy Days :" << endl;
    l1.search_by_title("Happy Days");
    
     cout<<"\nReversed playlist:"<<endl;
    l1.reverse_list();

    cout << "\nDeleting song with title Rain:" << endl;
    l1.del_by_title("Rain");
    cout<<"\nUpdated playlist:"<<endl;
    l1.play_song();

    cout << "\nDelete a song with id 41:" << endl;
    l1.del_by_id(41); 

    cout<<"\nUpdated playlist:"<<endl;
    
    l1.play_song();
    
    return 0;
}