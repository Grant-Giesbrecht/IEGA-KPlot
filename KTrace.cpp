//
//  KTrace.cpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/9/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//
//
//  This class is only a wrapper for info about a trace in a KGraph. It doesn't do any plotting
//  because it is only used to make the code more organized.
//
//

#include "KTrace.hpp"

using namespace std;

/*
 KTrace default contructor
 */
KTrace::KTrace(){
    KTrace::trace_color = sf::Color::Black;
    
    null_pt = {-1, -1};
    type  = KT_TYPE_LINE;
    style = KT_STYLE_STD;
}

/*
 Constructor
 
 new_vals - vector of KPoints with which to initialze trace.
 */
KTrace::KTrace(std::vector<KPoint> new_vals){
    KTrace::points = new_vals;
    KTrace::trace_color = sf::Color::Black;
    
    null_pt = {-1, -1};
    type  = KT_TYPE_LINE;
    style = KT_STYLE_STD;
}

/*
 Constructor
 
 new_vals - vector of KPoints with which to initialze trace.
 nc - color of trace
 */
KTrace::KTrace(std::vector<KPoint> new_vals, sf::Color nc){
    KTrace::points = new_vals;
    KTrace::trace_color = nc;
    
    null_pt = {-1, -1};
    type  = KT_TYPE_LINE;
    style = KT_STYLE_STD;
}

/*
 Destructor
 */
KTrace::~KTrace(){
    
}

/*
 Specify the points for the KTrace object (overrides any old points)
 
 new_vals - vector of KPoints with which to intialize trace
 
 Void return
 */
void KTrace::setPoints(std::vector<KPoint> new_vals){
    KTrace::points = new_vals;
}

/*
 Add a point to the trace
 
 x - x component
 y - y component
 
 Void return
 */
void KTrace::addPoint(double x, double y){
    KPoint kpt = {x, y};
    KTrace::points.push_back(kpt);
}

/*
 Get a copy of the KPoint specified by 'idx'. (Same as operator())
 
 idx - index of point
 
 Returns the
 */
KPoint& KTrace::getPoint(int idx, bool& success){

    //Protect bounds
    if (idx >= KTrace::points.size() || idx < 0){
        success = false;
        return null_pt;
    }
    
    success = true;
    return KTrace::points[idx];
}

/*
 Get a copy of the KPoint specified by 'idx'. (Same as getPoint())
 
 idx - index of point
 
 Returns the
 */
KPoint& KTrace::operator()(int idx){
    
    //Protect bounds
    if (idx >= KTrace::points.size() || idx < 0){
        return null_pt;
    }
    
    return KTrace::points[idx];
}


/*
 Return number of points in trace
 */
int KTrace::size(){
    return KTrace::points.size();
}

/*
 Set trace color
 
 nc - new color
 
 Void return
 */
void KTrace::setColor(sf::Color nc){
    KTrace::trace_color = nc;
}

/*
 Set trace type
 
 nt - new trace type
 
 Void return
 */
void KTrace::setType(int nt){
    KTrace::type = nt;
}

/*
 Set trace style
 
 ns - new style
 
 Void return
 */
void KTrace::setStyle(int ns){
    KTrace::type = ns;
}

/*
 Get magnitude of KPoint (as a vector)
 
 kp - KPoint to measure
 
 Returns magnitude
 */
double vec_mag(KPoint kp){
    return sqrt( kp.x*kp.x + kp.y*kp.y );
}

/*
 Return vector addition of KPoints a & b. Operation: ret a+b
 
 a - vector 1
 b - vector 2
 
 Returns a+b KPoint
 */
KPoint vec_add(KPoint a, KPoint b){
    KPoint kp = {a.x + b.x, a.y + b.y};
    return kp;
}

/*
 Return vector subtraction of KPoints a & b. Operation: ret a-b
 
 a - vector 1
 b - vector 2
 
 Returns a-b KPoint
 */
KPoint vec_sub(KPoint a, KPoint b){
    KPoint kp = {a.x - b.x, a.y - b.y};
    return kp;
}

/*
 Return vector multiplication of KPoint a & double b. Operation: ret a*b
 
 a - vector
 b - scalar multiple
 
 Returns KPoint a*b
 */
KPoint vec_mult(KPoint a, double b){
    KPoint kp = {a.x*b, a.y*b};
    return kp;
}















