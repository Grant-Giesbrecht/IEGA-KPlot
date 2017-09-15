//
//  KGraph.cpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/9/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//

#include "KGraph.hpp"

/*
 Constructor
 */
KGraph::KGraph(){ //NO initializer list required for void_trace because no arguments requrired
    
    //Default bounds
    x_min = -10;
    x_max = 10;
    y_min = -10;
    y_max = 10;
    
    //Default ticks
    tick_small = 1;
    tick_big = 5;
    tick_num = 10;
    
    //Default legend position (upper-right corner)
    legend_x = 1;
    legend_y = 0;
    
    //Default labels
    x_label = "X-Axis";
    y_label = "Y-Axis";
    title = "Title";
    
    //Default colors
    background_color = sf::Color(250, 250, 250);
    axes_color = sf::Color::Black;
    title_color = sf::Color::Black;
    grid_color = sf::Color(150, 150, 150);
    legend_background = sf::Color::White;
    
    if (!main_font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    
    show_legend = false;
}

/*
 Destructor
 */
KGraph::~KGraph(){
    
}

/*
 Add named trace to graph
 
 name - name to assign to trace
 nt - trace to add
 
 Void return
 */
void KGraph::addTrace(std::string name, KTrace nt){
    
    named_trace nnt = {name, nt};
    traces.push_back(nnt);
    
}

/*
 Access trace reference via trace name.
 
 search_name - name of trace for which to search
 
 Returns reference to trace (if found)
 */
KTrace& KGraph::getTrace(std::string search_name, bool& success){
    
    for (int i = 0 ; i < traces.size() ; i++){
        if (traces[i].name == search_name){
            success = true;
            return traces[i].trace;
        }
    }
    
    success = false;
    return void_trace;
}

/*
 Set font of graph
 
 nf - new font for graph
 
 Void return
 */
void KGraph::setFont(sf::Font nf){ //For axes and title and legend
    
    main_font = nf;
    
}

/*
 Set bounds of graph
 
 x_min - x min
 x_max - x max
 y_min - y min
 y_max - y max
 
 Void return
 */
void KGraph::setBounds(double x_min, double x_max, double y_min, double y_max){ //Set plot bounds
    
    KGraph::x_min = x_min;
    KGraph::x_max = x_max;
    KGraph::y_min = y_min;
    KGraph::y_max = y_max;
    
}

/*
 Set KGraph property
 
 prop - property to adjust
 val - new property value
 
 Void return
 */
void KGraph::set(int prop, bool val){ //Set specified property
    
    switch (prop) {
        case KG_PROP_LEGEND_ON:
            show_legend = val;
            break;
        default:
            break;
    }
    
}

/*
 Set position of legend
 
 x - x position in percent/100 of graph size (not pixel coordinates)
 y - y position in percent/100 of graph size (not pixel coordinates)
 
 Void return
 */
void KGraph::setLegendPosition(double x, double y){ //Set position of legend, in %/100 of graph size, NOT PIXELS
    legend_x = x;
    legend_y = y;
}

/*
 Return the title of the graph
 */
std::string KGraph::getTitle(){
    return title;
}











