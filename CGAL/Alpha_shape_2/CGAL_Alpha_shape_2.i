%module CGAL_Alpha_shape_2

#define CGAL_DO_NOT_DEFINE_FOR_ALPHA_SHAPE_2

//Special treatment for enum in java
#ifdef SWIGJAVA
%include "enums.swg"
%javaconst(1);
#endif


%include "../common.i"
%import  "../Common/Macros.h"
%import  "../Kernel/Point_2.h"
%import  "../Kernel/Segment_2.h"
%import  "../Kernel/Triangle_2.h"
%import  "../Kernel/Weighted_point_2.h"
%include "../Common/Input_iterator.h"

//include files
%{
  #include "../Kernel/typedefs.h"
  #include "Alpha_shape_2.h"
  #include "alpha_shape_handles.h"
  #include "../Triangulation_2/triangulation_iterators.h"
%}

%include "config.i"

//definitions
%include "Alpha_shape_2.h"
%include "alpha_shape_handles.h"
%import "../Triangulation_2/triangulation_iterators.h"
%import "../Triangulation_2/Triangulation_2.h"
%import "../Triangulation_2/Delaunay_triangulation_2.h"
%import "../Triangulation_2/Regular_triangulation_2.h"


//vertex range
%include "std_pair.i"
%template(Vertex_range) std::pair<double,double>;

//Face Interval_3
%include "../Common/triple.h"
%template(Face_Interval_3)  CGAL_SWIG::Triple<double,double,double>;

%pragma(java) jniclassimports=%{import CGAL.Kernel.Point_2; import CGAL.Kernel.Weighted_point_2;  import java.util.Iterator; import java.util.Collection;%}

//typemap for point input iterator
Typemap_for_Input_iterator(Weighting_helper<CGAL::Tag_false>::Point_range,Point_2,Point_2::cpp_base,SWIGTYPE_p_Point_2,"(LCGAL/Kernel/Point_2;)J",make_alpha_shape)
//typemap for weighted point input iterator
Typemap_for_Input_iterator(Weighting_helper<CGAL::Tag_true>::Point_range,Weighted_point_2,Weighted_point_2::cpp_base,SWIGTYPE_p_Weighted_point_2,"(LCGAL/Kernel/Weighted_point_2;)J",make_alpha_shape)

%import "declare_alpha_shape_2.i"

#ifdef   SWIG_EXPOSE_ALPHA_SHAPE_2
Declare_alpha_shape_2(Alpha_shape_2,CGAL_AS2)
#endif //SWIG_EXPOSE_ALPHA_SHAPE_2
#ifdef   SWIG_EXPOSE_WEIGHTED_ALPHA_SHAPE_2
Declare_weighted_alpha_shape_2(Weighted_alpha_shape_2,CGAL_WAS2)
#endif //SWIG_EXPOSE_WEIGHTED_ALPHA_SHAPE_2
