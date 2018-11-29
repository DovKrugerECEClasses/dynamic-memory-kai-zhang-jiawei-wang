/*
    Author: Kai Zhang& Jiawei Wang
    Stevens Institute of Technology
 */
#include<vector>
#include<iostream>
#include<cmath>
#include<fstream>
#include<string>
using namespace std;

const double PI=3.14159265358979;

class Vector{
private:
    double x,y,z;
public:
    Vector(double x=0,double y=0,double z=0):x(x),y(y),z(z){}
//    Vector add(const Vector& a){
//        return(Vector(x+a.x, y+a.y, z+a.z));
//    }
//    Vector minus(const Vector& a){
//        return(Vector(x-a.x, y-a.y, z-a.z));
//    }
    double getX(){return x;}
    double getY(){return y;}
    double getZ(){return z;}
    friend ostream& operator << (ostream& s, const Vector& a){
        return s<<a.x<<' '<<a.y<<' '<<a.z;
    }
};

class Panel{
private:
    Vector v1,v2,v3;
public:
    Panel(Vector v1, Vector v2, Vector v3):v1(v1), v2(v2), v3(v3){}
    Vector getv1(){return v1;}
    Vector getv2(){return v2;}
    Vector getv3(){return v3;}
};

class Shape{
private:
    double x,y,z;
public:
    Shape(double x=0, double y=0, double z=0): x(x), y(y),z(z){}
    const double getX(){
        return x;
    }
    const double getY(){
        return y;
    }
    const double getZ(){
        return z;
    }
    Vector getNormal(Panel p){

        double a = ((p.getv2().getY() - p.getv1().getY()) * (p.getv3().getZ() - p.getv1().getZ()) - (p.getv2().getZ() - p.getv1().getZ()) * (p.getv3().getY() - p.getv1().getY()));
        double b = ((p.getv2().getZ() - p.getv1().getZ()) * (p.getv3().getX() - p.getv1().getX()) - (p.getv2().getX() - p.getv1().getX()) * (p.getv3().getZ() - p.getv1().getZ()));
        double c = ((p.getv2().getX() - p.getv1().getX()) * (p.getv3().getY() - p.getv1().getY()) - (p.getv2().getY() - p.getv1().getY()) * (p.getv3().getX() - p.getv1().getX()));
        return Vector(a,b,c);
    }

    //virtual const double volume()=0;
    virtual vector<Panel> getPanel(){};

};

class Cube : public Shape{
private:
    double s;
public:
    Cube(double s): Shape(0,0,0), s(s){}
    double x=getX();
    double y=getY();
    double z=getZ();
    vector<Panel> getPanel(){
        // 8 points
        Vector p1(x,y,z);
        Vector p2(x+s,y,z);
        Vector p3(x,y+s,z);
        Vector p4(x,y,z+s);
        Vector p5(x+s,y+s,z);
        Vector p6(x+s,y,z+s);
        Vector p7(x,y+s,z+s);
        Vector p8(x+s,y+s,z+s);
        vector<Panel> triangle;
        // 12 triangles
        triangle.emplace_back(Panel(p1,p2,p3));
        triangle.emplace_back(Panel(p2,p3,p5));
        triangle.emplace_back(Panel(p1,p2,p4));
        triangle.emplace_back(Panel(p2,p4,p6));
        triangle.emplace_back(Panel(p1,p3,p4));
        triangle.emplace_back(Panel(p3,p4,p7));
        triangle.emplace_back(Panel(p2,p5,p6));
        triangle.emplace_back(Panel(p4,p6,p7));
        triangle.emplace_back(Panel(p6,p7,p8));
        triangle.emplace_back(Panel(p3,p5,p7));
        triangle.emplace_back(Panel(p5,p7,p8));
        return triangle;
    }
    void translate(double x1, double y1, double z1){
        this->x+=x1;
        this->y+=y1;
        this->z+=z1;
    }
    const double volume(){
        return s*s*s;
    }
    void write(const string& file){
        ofstream out(file, ofstream::app);
        out << "solid OpenSCAD_Model" << endl;
        for(auto i = getPanel().begin(); i != getPanel().end(); i++) {
            Vector facetNormal = getNormal(*i);
            out <<"  facet normal " << facetNormal << endl;
            out << "    outer loop" << endl;
            out << "      vertex " << (*i).getv1() << endl;
            out << "      vertex " << (*i).getv2() << endl;
            out << "      vertex " << (*i).getv3() << endl;
            out << "    endloop" << endl;
            out << "  endfacet" << endl;
        }
        out << "endsolid OpenSCAD_Model" << endl;
        out.close();
    }
};

class Cylinder : public Shape{
private:
    double r,height;
public:
    Cylinder(double r, double height): Shape(getX(),getY(),getZ()),r(r),height(height){}
    double x=getX();
    double y=getY();
    double Bz=getZ();
    double Uz=getZ()+height;

    vector<Panel> getPanel(){
        double perangle=2*PI/20;
        vector<Panel> triangle;
        Vector o1(x,y,Bz);
        Vector o2(x,y,Uz);
        for(int k=0; k<20; k++) {
            double angle = perangle * k;
            double angle1 = perangle * (k + 1);
            Vector p1(r*cos(angle)+x,r*sin(angle),Bz);
            Vector p2(r*cos(angle1)+x,r*sin(angle1),Bz);
            Vector p3(r*cos(angle)+x,r*sin(angle),Uz);
            Vector p4(r*cos(angle1)+x,r*sin(angle1),Uz);
            triangle.emplace_back(Panel(o1,p1,p2));
            triangle.emplace_back(Panel(o2,p3,p4));
            triangle.emplace_back(Panel(p1,p3,p4));
            triangle.emplace_back(Panel(p1,p2,p4));

        }
        return triangle;
    }

};

class Design :public Shape{
private:
    vector<Shape> shapes;
public:
    Design(){}
    void add(const Shape& s){
        shapes.push_back(s);
    }
    void write(const string& file){
        ofstream out(file, ofstream::app);
        out << "solid OpenSCAD_Model" << endl;
        for(auto i = getPanel().begin(); i != getPanel().end(); i++) {
            Vector facetNormal = getNormal(*i);
            out <<"  facet normal " << facetNormal << endl;
            out << "    outer loop" << endl;
            out << "      vertex " << (*i).getv1() << endl;
            out << "      vertex " << (*i).getv2() << endl;
            out << "      vertex " << (*i).getv3() << endl;
            out << "    endloop" << endl;
            out << "  endfacet" << endl;
        }
        out << "endsolid OpenSCAD_Model" << endl;
        out.close();
    }
};

int main() {
    Design d;
    double s = 10;
    Cube c(s);
    //double x=-20;
    //double y=0;
    //double z=0;
    // rotate??
    cout << c.volume() << '\n';
    c.write("out.stl"); // how to get all my shapes into the same file
    d.add(c);
    d.write("test1.stl");
    c.translate(-20,0,0);
    double r = 10, height  = 20;
    Cylinder cyl(r, height);
    d.add(cyl);
    d.write("test.stl");

}
