#ifndef SWIG_CGAL_TRIANGULATION_3_TRIANGULATION_HANDLES_H
#define SWIG_CGAL_TRIANGULATION_3_TRIANGULATION_HANDLES_H

#include <SWIG_CGAL/Common/Macros.h>

template <class Triangulation,class Point>
class CGAL_Cell_handle;

template <class Triangulation,class Point>
class CGAL_Vertex_handle{
  typename Triangulation::Vertex_handle data;
public:
  typedef typename Triangulation::Vertex_handle cpp_base;
  typedef CGAL_Cell_handle<Triangulation,Point> Cell_handle;
  
  const typename Triangulation::Vertex_handle& get_data() const {return data;}
  typename Triangulation::Vertex_handle& get_data_ref() {return data;}

  CGAL_Vertex_handle():data(NULL){}
  CGAL_Vertex_handle(typename Triangulation::Vertex_handle v):data(v){}
  
  FORWARD_CALL_0_PTR(Point,point)
  FORWARD_CALL_0_PTR(Cell_handle,cell)
  FORWARD_CALL_1_PTR(void,set_cell,Cell_handle)
  FORWARD_CALL_1_PTR(void,set_point,Point)
  FORWARD_CALL_0_PTR(bool,is_valid)
  FORWARD_CALL_1_PTR(bool,is_valid,bool)

  
  bool equals(const CGAL_Vertex_handle<Triangulation,Point>& v){
    return data==v.get_data();
  }
  
  #ifdef SWIGPYTHON
  bool __ne__(const CGAL_Vertex_handle<Triangulation,Point>& v){return !equals(v);}
  #endif
};


template <class Triangulation,class Point>
class CGAL_Cell_handle{
  typename Triangulation::Cell_handle data;
  
public:
  typedef typename Triangulation::Cell_handle cpp_base;
  typedef CGAL_Vertex_handle<Triangulation,Point> Vertex_handle;
  typedef CGAL_Cell_handle<Triangulation,Point> Cell_handle;

  CGAL_Cell_handle():data(NULL){}
  CGAL_Cell_handle(typename Triangulation::Cell_handle v):data(v){}
  const typename Triangulation::Cell_handle& get_data() const {return data;}
  typename Triangulation::Cell_handle& get_data_ref() {return data;}
  
  
  FORWARD_CALL_1_PTR(Vertex_handle,vertex,int)
  FORWARD_CALL_1_PTR(int,index,Vertex_handle)
  FORWARD_CALL_1_PTR(bool,has_vertex,Vertex_handle)
  FORWARD_CALL_1_PTR(Cell_handle,neighbor,int)
  FORWARD_CALL_1_PTR(int,index,Cell_handle)
  FORWARD_CALL_1_PTR(bool,has_neighbor,Cell_handle)
  FORWARD_CALL_2_PTR(void,set_vertex,int,Vertex_handle)
  FORWARD_CALL_4_PTR(void,set_vertices,Vertex_handle,Vertex_handle,Vertex_handle,Vertex_handle)
  FORWARD_CALL_2_PTR(void,set_neighbor,int,Cell_handle)
  FORWARD_CALL_4_PTR(void,set_neighbors,Cell_handle,Cell_handle,Cell_handle,Cell_handle)
  FORWARD_CALL_0_PTR(bool,is_valid)
  FORWARD_CALL_1_PTR(bool,is_valid,bool)
  FORWARD_CALL_2_PTR(bool,is_valid,bool,int)
  
  bool equals(const CGAL_Cell_handle<Triangulation,Point>& c){
    return data==c.get_data();
  }  

  #ifdef SWIGPYTHON
  bool __ne__(const CGAL_Cell_handle<Triangulation,Point>& c){return !equals(c);}
  #endif  

  //FORWARD_CALL_2(bool has_vertex,Vertex_handle, int & i)  
  //bool has_neighbor ( Cell_handle n, int & i)  
};

#endif //SWIG_CGAL_TRIANGULATION_3_TRIANGULATION_HANDLES_H