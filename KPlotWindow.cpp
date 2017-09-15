//
//  KPlotWindow.cpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/10/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//

#include "KPlotWindow.hpp"

using namespace std;

/*
 Default constructor
 */
KPlotWindow::KPlotWindow() : KPlotWindow(800, 600, "IEGA Plot") {
}

/*
 Constructor - specify dimensions and windows name
 
 width - window width (in pixels)
 height - window height (in pixels)
 title - window title
 */
KPlotWindow::KPlotWindow(int width, int height, std::string title) : window(sf::VideoMode(width, height), title) {
    
    bool show_toolbar = true;
    bool show_tabbar = false;
    int active_tab = -1;
    int window_style = KP_WSTYLE_CLASSIC;
    
}

/*
 Add a KPlotTab to the window. Assigns a defualt name to the tab
 
 tab - KPlotTab to add.
 
 Void return
 */
void KPlotWindow::add_tab(KPlotTab tab){
    
    string title("Tab ");
    title = title + to_string(tabs.size());
    
    KPlotWindow::add_tab(tab, title);
    
}

/*
 Add a KPlotTab to the window.
 
 tab - KPlotTab to add.
 tab_title - title of new tab
 
 Void return
 */
void KPlotWindow::add_tab(KPlotTab tab, std::string tab_title){
    
    named_tab tt = {tab, tab_title};
    KPlotWindow::tabs.push_back(tt);
    
}

/*
 Deletes the first tab by the name 'tab_title'.
 
 tab_title - title of tab to delete
 
 Returns true if specified tab found and deleted.
 */
bool KPlotWindow::delete_tab(std::string tab_title){
    
    //Scan for name
    for (int i = 0 ; i < KPlotWindow::tabs.size() ; i++){
        if (KPlotWindow::tabs[i].title == tab_title){
            KPlotWindow::tabs.erase(KPlotWindow::tabs.begin() + i); //Delete tab if found
            return true;
        }
    }
    
    return false;
}

/*
 Deletes the tab specified by idx.
 
 idx - index of the tab to delete.
 
 Returns true if tab found and deleted
 */
bool KPlotWindow::delete_tab(int idx){
    
    //Ensure no overflow
    if (idx >= KPlotWindow::tabs.size() || idx < 0){
        return false;
    }
    
    //Delete tab
    KPlotWindow::tabs.erase( KPlotWindow::tabs.begin() + idx );
    
    return true;
}

/*
 Searches for the tab specified by 'tab_title'. Returns a reference to that tab if found, else returns a returns any KPlotTab tab & reports false via 'success' arg.
 
 tab_title - title of tab for which to search
 success - set to true if found, else set to false
 
 Returns reference to specified tab (if found).
 */
KPlotTab& KPlotWindow::tab(std::string tab_title, bool& success){
    
    //Scan for name
    for (int i = 0 ; i < KPlotWindow::tabs.size() ; i++){
        if (KPlotWindow::tabs[i].title == tab_title){
            success = true;
            return KPlotWindow::tabs[i].tab;
        }
    }
    
    //Tab not found
    success = false;
    return unused_tab;
    
}

/*
 Searches for the tab specified by 'idx'. Returns a reference to that tab if found, else returns a returns any KPlotTab tab & reports false via 'success' arg.
 
 idx - index of tab for which to search
 success - set to true if found, else set to false
 
 Returns reference to specified tab (if found).
 */
KPlotTab& KPlotWindow::tab(int idx, bool& success){
    
    //Check bounds
    if (idx >= tabs.size() || idx < 0){
        success = false;
        return unused_tab;
    }
    
    //Return tabs
    success = true;
    return tabs[idx].tab;
    
}

/*
 Set properties for the class
 
 prop - property to set
 val - value of property
 
 Void return
 */
void KPlotWindow::set(int prop, bool val){
    
    switch(prop){
        case(KP_SET_SHOW_TOOLBAR):
            show_toolbar = val;
            break;
        case(KP_SET_SHOW_TABBAR):
            show_tabbar = val;
            break;
    }
    
}

/*
 Set properties for the class
 
 prop - property to set
 val - value of property
 
 Void return
 */
void KPlotWindow::set(int prop, int val){
    switch(prop){
        case(KP_SET_ACTIV_TAB):
            active_tab = val;
            break;
        case(KP_SET_WSTYLE):
            window_style = val;
            break;
    }
}

/*
 Set properties for the class
 
 prop - property to set
 val - value of property
 
 Void return
 */
void KPlotWindow::set(int prop, std::string val){
    switch(prop){
        case(KP_SET_ACTIV_TAB):
            
            active_tab = -1;
            
            //Scan for name
            bool success = false;
            for (int i = 0 ; i < KPlotWindow::tabs.size() ; i++){
                if (KPlotWindow::tabs[i].title == val){
                    active_tab = i;
                    break; //Break for loop
                }
            }
            break;
    }
}

/*
 Tell KPlotWindow to update the window. This involves:
    1. Drawing tool bar (if set)
    2. Drawing tab bar (if set)
    3. Drawing any active tabs
 
 TODO: The whole thing
 
 */
void KPlotWindow::draw_window(){
    
}












