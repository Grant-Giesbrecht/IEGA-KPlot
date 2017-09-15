//
//  KPlotTab.cpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/10/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//

#include "KPlotTab.hpp"

/*
 Constructor
 */
KPlotTab::KPlotTab(){
    int rows = -1;
    int cols = -1;
}

/*
 Add a graph to the tab
 
 ng - new graph to add
 
 Void return
 */
void KPlotTab::add_graph(KGraph ng){
    located_graph temp = {ng, -1, -1, -1, -1};
    graphs.push_back(temp);
}

/*
 Deletes the graph specified by 'idx'.
 
 idx - index of graph to delete
 
 Returns true if the graph was found and deleted
 */
bool KPlotTab::delete_gaph(int idx){
    
    if (idx >= graphs.size() || idx < 0){
        return false;
    }
    
    graphs.erase(graphs.begin() + idx);
    return true;
}

/*
 Deletes the graph specified by title
 
 title - name of title (saved in KGraph object) of graph to delete
 
 Returns true if graph found and deleted
 */
bool KPlotTab::delete_gaph(std::string title){
    
    int idx = get_index_form_title(title);
    
    return delete_gaph(idx);
}

/*
 Returns a referece to the graph specified by idx.
 
 idx - index of graph
 success - bool reference in which success state is saved. (True: Graph found and returned, False: Graph not found)
 
 Returns a reference to the graph if found, else it returns an arbitrary KGraph reference.
 */
KGraph& KPlotTab::get_graph(int idx, bool& success){
    
    if (idx >= graphs.size() || idx < 0){
        success = false;
        return null_graph;
    }
    
    return graphs[idx].graph;
}

/*
 Returns a referece to the graph specified by title.
 
 title - title of graph
 success - bool reference in which success state is saved. (True: Graph found and returned, False: Graph not found)
 
 Returns a reference to the graph if found, else it returns an arbitrary KGraph reference.
 */
KGraph& KPlotTab::get_graph(std::string title, bool& success){
    
    int idx = get_index_form_title(title);
    
    return get_graph(idx, success);
}

/*
 Specify the dimensions of the tab's grid layout
 
 nrows - new number of rows
 ncols - new number of columns
 
 Void return
 */
void KPlotTab::layout_dimensions(int nrows, int ncols){
    
    rows = nrows;
    cols = ncols;
}

/*
 Specify the location of the specified graph
 
 idx - index of graph
 r - row of location of graph (in terms of the grid-layout, not pixel dimensions)
 c - col of location of graph (in terms of the grid-layout, not pixel dimensions)
 
 Void return
 */
void KPlotTab::graph_location(int idx, int r, int c){
    
    if (idx >= graphs.size() || idx < 0){
        return;
    }
    
    graphs[idx].r_tl = r;
    graphs[idx].c_tl = c;
    graphs[idx].r_br = r;
    graphs[idx].c_br = c;
}

/*
 Specify the location of the specified graph
 
 idx - index of graph
 r_tl - row of location of graph's top left corner (in terms of the grid-layout, not pixel dimensions)
 c_tl - col of location of graph's top left corner (in terms of the grid-layout, not pixel dimensions)
 r_br - row of location of graph's bottom right corner (in terms of the grid-layout, not pixel dimensions)
 c_br - col of location of graph's bottom right corner (in terms of the grid-layout, not pixel dimensions)
 
 Void return
 */
void KPlotTab::graph_location(int idx, int r_tl, int c_tl, int r_br, int c_br){
    
    if (idx >= graphs.size() || idx < 0){
        return;
    }
    
    graphs[idx].r_tl = r_tl;
    graphs[idx].c_tl = c_tl;
    graphs[idx].r_br = r_br;
    graphs[idx].c_br = c_br;
}

/*
 Specify the location of the specified graph
 
 title - title of graph
 r - row of location of graph (in terms of the grid-layout, not pixel dimensions)
 c - col of location of graph (in terms of the grid-layout, not pixel dimensions)
 
 Void return
 */
void KPlotTab::graph_location(std::string title, int r, int c){
    
    int idx = get_index_form_title(title);
    
    graph_location(idx, r, c);
}

/*
 Specify the location of the specified graph
 
 idx - index of graph
 r_tl - row of location of graph's top left corner (in terms of the grid-layout, not pixel dimensions)
 c_tl - col of location of graph's top left corner (in terms of the grid-layout, not pixel dimensions)
 r_br - row of location of graph's bottom right corner (in terms of the grid-layout, not pixel dimensions)
 c_br - col of location of graph's bottom right corner (in terms of the grid-layout, not pixel dimensions)
 
 Void return
 */
void KPlotTab::graph_location(std::string title, int r_tl, int c_tl, int r_br, int c_br){
    
    int idx = get_index_form_title(title);
    
    graph_location(idx, r_tl, c_tl, r_br, c_br);
}

/*
 Draw the tab, including all of the graphs inside the tab.
 */
void KPlotTab::draw_tab(sf::RenderWindow window, int left_bound, int right_bound, int top_bound, int low_bound, int window_style){
    
}

// ================================== Private Functions =================================

/*
 Returns the index of the first graph with the title 'title'.
 
 title - title to search for
 
 Returns index if found, if not title match, returns -1
 */
int KPlotTab::get_index_form_title(std::string title){
    
    for (int i = 0 ; i < graphs.size() ; i++){
        if (graphs[i].graph.getTitle() == title){
            return i;
        }
    }
    
    return -1;
}


























