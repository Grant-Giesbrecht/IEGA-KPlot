//
//  KTrace.hpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/9/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//

#ifndef KTrace_hpp
#define KTrace_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <ctgmath>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#define KT_TYPE_LINE 0
#define KT_TYPE_POINT 1

//Line
#define KT_STYLE_STD 0
#define KT_STYLE_DASH 1
#define KT_STYLE_DOT 2
#define KT_STYLE_DASHDOT 3

//Point
#define KT_STYLE_POINT 0 //(Equivilent to STD)
#define KT_STYLE_STAR 4
#define KT_STYLE_V 5
#define KT_STYLE_O 6

typedef struct{
    double x;
    double y;
}KPoint;

class KTrace{
    
public:
    
    KTrace();
    KTrace(std::vector<KPoint> new_vals);
    KTrace(std::vector<KPoint> new_vals, sf::Color nc);
    ~KTrace();
    
    void setPoints(std::vector<KPoint> new_vals);
    void addPoint(double x, double y);
    
    KPoint& getPoint(int idx, bool& success);
    KPoint& operator()(int idx);
    int size();
    
    void setType(int nt);
    void setStyle(int ns);
    void setColor(sf::Color nc);
    
private:
  
    int type;
    int style;
    
    sf::Color trace_color;
    
    std::vector<KPoint> points;
    
    KPoint null_pt;
    
};

double vec_mag(KPoint kp);
KPoint vec_add(KPoint a, KPoint b);
KPoint vec_sub(KPoint a, KPoint b);
KPoint vec_mult(KPoint a, double b);

#endif /* KTrace_hpp */
