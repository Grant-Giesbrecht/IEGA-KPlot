//
//  kpgraphics.cpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/11/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//


#include "kpgraphics.hpp"

using namespace std;

/*
 Converts a line with no thickness to a vector of tessellated points from which a thick line can be rendered.
 
 t - trace to tesselate
 thickness - thickness of the line (in pixels)
 
 Returns a vector of KPoints constituting the tessellated trace.
 */
std::vector<KPoint> tessellate_line(KTrace t, int thickness){
    
    vector<KPoint> pts;
    
    //Ensure t contains at least 2 points
    if (t.size() < 2){
        return pts;
    }
    
    //Determine vector components for each line segment
    KPoint A;
    vector<KPoint> m; //x & y not being used for position, rather ∆x & ∆y for slope
    for (int i = 1 ; i < t.size() ; i++){
        KPoint kpt = {t(i).x - t(i-1).x, t(i).y - t(i-1).y};
        m.push_back(kpt);
    }
    
    // ======== Calculate tessellation vertices for first point ==========
    
    //Calculate A-vector & scale
    A.x = -1*m[0].y;
    A.y = m[0].x;
    double mag = vec_mag(A);
    A = vec_mult(A, thickness/2/mag);
    
    //Flip y (because y counts from top)
    A.y = -1*A.y;
    
    //Calculate verticies
    pts.push_back(vec_add(t(0), A));
    pts.push_back(vec_sub(t(0), A));
    
    // ======= Calculate tessellation verticies for middle points ==========
    
    for (int i = 1 ; i < m.size() ; i++){
        
        //Calculate A-vector & scale
        A = vec_sub(m[i-1], m[i]);
        vec_mult(A, thickness/2/vec_mag(A));
        
        //Flip y (because y counts from top)
        A.y = -1*A.y;
        
        //Calculate verticies
        pts.push_back(vec_add(t(i), A));
        pts.push_back(vec_sub(t(i), A));
        
    }
    
    // ======== Calculate tessellation verticies for final point
    
    //Calculate A-vector & scale
    A.x = -1*m[m.size()-1].y;
    A.y = m[m.size()-1].x;
    mag = vec_mag(A);
    A = vec_mult(A, thickness/2/mag);
    
    //Flip y (because y counts from top)
    A.y = -1*A.y;
    
    //Calculate verticies
    pts.push_back(vec_add(t(t.size()-1), A));
    pts.push_back(vec_sub(t(t.size()-1), A));
    
    //Return tessellation verticies
    return pts;
}

/*
 Converts a line with no thickness to a set of vectors of tessellated points. Each set of points can be used to make a small line segment, all of these segments (in the outermost vector) constitue the origional line broken up into the pattern described by c1-5.
 
 t - trace to segment and tesselate
 thickness - thickness of line in pixels
 c1-5 - (pattern description terms) size (in pixels) of each component of the repeating pattern to use in segmenting 't'. If one is set to -1, it and the following pattern description terms will be ignored and the repeat will begin.
 
 Returns a vector of vectors of KPoints constituting the tesselated and segmented trace.
 */
std::vector<std::vector<KPoint> > tessellate_pattern_line(KTrace t, int thickness, int c1, int c2, int c3, int c4, int c5){
    
}

/*
 Converts a series of points indicating the verticies of a trianglestrip vertex array to the vertexarray it represents.
 
 tp - tessellated points (aka vertex points)
 va - vertexarray to modify
 c - color to make 'va'
 
 Void return
 */
void tes_to_vertexarray(std::vector<KPoint> tp, sf::VertexArray* va, sf::Color c){
    
    //Set VA settings
    va->clear();
    va->resize(tp.size());
    va->setPrimitiveType(sf::TriangleStrip);
    
    //Add points
    for (int i = 0 ; i < tp.size() ; i++){
        va->append(sf::Vertex(sf::Vector2f(tp[i].x, tp[i].y), c));
    }
    
}




















