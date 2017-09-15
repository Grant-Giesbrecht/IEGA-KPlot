//
//  kpgraphics.hpp
//  SFML Test 1
//
//  Created by Grant Giesbrecht on 9/11/17.
//  Copyright © 2017 IEGA Software. All rights reserved.
//
//
//  Includes functions to help KPlot with graphics.
//
//

#ifndef kpgraphics_hpp
#define kpgraphics_hpp

#include <stdio.h>
#include <vector>

#include "KTrace.hpp"

std::vector<KPoint> tessellate_line(KTrace t, int thickness);

std::vector<std::vector<KPoint> > tessellate_pattern_line(KTrace t, int thickness, int c1, int c2, int c3, int c4, int c5);

void tes_to_vertexarray(std::vector<KPoint> tp, sf::VertexArray* va, sf::Color c);



#endif /* kpgraphics_hpp */
