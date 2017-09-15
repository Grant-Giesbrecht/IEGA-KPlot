//
//  KPlotWindow.hpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/10/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//
//
//  The KPlot window object contains one or more KPlotTab objects. The KPlotWindow only has 4
//  jobs: 1. Draw the toolbar 2. Draw the tab-bar (if 2+ tabs or requested for always draw)
//  3. Organize the KPlotTab(s) by selecting which one is active (and all others are inactive)
//  and specifying the coordinates of the area in which the KPlotTabs may plot and 4. Listening
//  for mouse and keyboard events. These could be changing the KPlotTab's graph, changing the
//  active KPlotTab, or a miriad of other things.
//
//

#ifndef KPlotWindow_hpp
#define KPlotWindow_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "KPlotTab.hpp"

typedef struct{
    KPlotTab tab;
    std::string title;
}named_tab;

#define KP_WSTYLE_CLASSIC 0
#define KP_WSTYLE_LIGHT 1
#define KP_WSTYLE_OKUDAGRAM 2

#define KP_SET_SHOW_TOOLBAR 0
#define KP_SET_SHOW_TABBAR 1
#define KP_SET_ACTIV_TAB 2
#define KP_SET_WSTYLE 3

class KPlotWindow{
public:
    
    //Constructors
    KPlotWindow();
    KPlotWindow(int width, int height, std::string title);
    
    //Add/edit/delete tabs
    void add_tab(KPlotTab tab); //Add tab (default title applied)
    void add_tab(KPlotTab tab, std::string tab_title); //Add tab (with title for reference)
    bool delete_tab(std::string tab_title); //Delete tab by title
    bool delete_tab(int idx); //Delte tab specified by index
    KPlotTab& tab(std::string tab_title, bool& success); //Access tab for editting
    KPlotTab& tab(int idx, bool& success); //Access tab for editing
    
    //Control window operation
    void set(int prop, bool val);
    void set(int prop, int val);
    void set(int prop, std::string val);
    
    //Updates the window
    void draw_window();
    
private:
    
    //Main window
    sf::RenderWindow window;
    
    //Tabs
    std::vector<named_tab> tabs;
    
    //Window Settings
    bool show_toolbar;
    bool show_tabbar;
    int active_tab;
    int window_style;
    
    //Blank OBJs for References
    KPlotTab unused_tab;
};

#endif /* KPlotWindow_hpp */












