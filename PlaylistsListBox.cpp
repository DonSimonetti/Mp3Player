//
// Created by matteo on 30/06/18.
//
#include "Mp3Player.h"
#include "PlaylistsListBox.h"
#include "PlayList.h"

PlaylistsListBox::PlaylistsListBox(wxWindow *parent, wxWindowID id, const wxPoint &pos, const wxSize &size) :
        wxListBox(parent,id,pos,size)
{
    printLists();
}

void PlaylistsListBox::update()
{
    wxListBox::Clear();
    printLists();
}

void PlaylistsListBox::printLists()
{
    unsigned int _pos=1;
    for(auto & item : Mp3Player::getInstancePtr()->playlists)
    {
        if(PlayList * list=dynamic_cast<PlayList*>(item.get()))
        {
            if (list->getName() == "#mainLibrary")
                wxListBox::Insert("Main Library", 0);
            else {
                string name = list->getName();
                wxListBox::Insert(name, _pos);
                _pos++;
            }
        }
    }
}
