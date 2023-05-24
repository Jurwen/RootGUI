#pragma once

#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
//#include <GL/glut.h>
#include <GL/freeglut.h>
#include <iostream>
#include <set>
using namespace std;

typedef struct {
	double r, g, b;
} COLOR;

enum line_color{
	Normal,
	Jet,
	Hierarchy
};


typedef struct Vertex {
	float x, y, z;
} Vertex;
typedef struct Face {
	Face(void) : vert_number(0), verts(0) {};
	int vert_number;
	Vertex **verts;
	float normal[3];
} Face;
typedef struct myMesh {
	myMesh(void) : vert_number(0), verts(0), face_number(0), faces(0) {};
	int vert_number;
	Vertex *verts;
	int face_number;
	Face *faces;
	vector<Vertex>point;
} myMesh;

typedef struct Whorls {
	vector<vector<int>> whorlAbove;
	vector<vector<int>> whorlBelow;
} Whorls;


class glArea :
	public QOpenGLWidget
{
	Q_OBJECT

public: 
	glArea(QWidget *parent = nullptr);
	~glArea();
	bool if_face, if_line, if_drawWhorlAbove, if_drawWhorlBelow, if_drawNodeAbove, if_drawNodeBelow, if_drawPlane;
	float alpha;
	float line_width;
	int line_color;
	double jet_max;
	double jet_min;
	double mesh_colorR;
	double mesh_colorG;
	double mesh_colorB;
	double back_colorR;
	double back_colorG;
	double back_colorB;

	bool editOn;
	bool editWhorlOn;
	int par;

	myMesh *mesh;
	Whorls whorls;
	vector<vector<int>> nodalRoots;
	vector<vector<double long>> vertexList;
	vector<vector<int>> edgeList;
	
	vector<vector<int>> adjVertex;
	std::set<int> junctions;
	vector<int> IDs;

	vector<vector<int>> juncAdj;
	map<int, std::vector<int> > childVertex;

	vector<int> whorls_inord;
	map<int, int> juncWhorlAbove, juncWhorlBelow;

	vector<double long> radius;
	vector<int> level;
	void adjustView();
	int faceDisplayList = 2;
	void draw_faces();
	vector<bool> showLevels = {0,1,1,1,1,1,1,1,1,1};
	//GLuint lineDisplayList = 1;
	vector<float> cent = {};
	vector<vector<float>> n = { {},{},{} }; //PCA axes
	int annotation_activated = 0;
	int hierarchyCap = 5;

	int parVisualize = -1, chiVisualize = -1, fchiVisualize = -1;
	int topWh = -1, botWh = -1;

	void sort_whorls();
	bool deleteWhorl(char c);
	bool addNewBox(int topJunc, int botJunc, bool above);

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);    
	void mouseReleaseEvent(QMouseEvent *event);
	void wheelEvent(QWheelEvent * event);
	
	void draw_lines();
	void draw_whorlsAbove();
	void draw_whorlsBelow();
	void draw_rootsAbove();
	void draw_rootsBelow();
	void draw_plane();

	void draw_labels();
	void label_junction(int idx, float h);
	void drawArrow(GLdouble x1, GLdouble y1, GLdouble z1, GLdouble x2, GLdouble y2, GLdouble z2, GLdouble D);

	void highlight_junction(int idx);
private:
	int skeleton_size;
	bool isRotate;
	bool isTranslate;

	
	int GLUTwindow_height;
	int GLUTwindow_width;
	int GLUTmouse[2] = { 0, 0 };
	int GLUTbutton[3] = { 0, 0, 0 };
	int GLUTarrows[4] = { 0, 0, 0, 0 };
	int GLUTmodifiers = 0;
	int scaling = 0;
	int translating = 0;
	int rotating = 0;
	float scale = 1.0;
	float center[3] = { 0.0, 0.0, 0.0 };
	float rotation[3] = { 0.0, 0.0, 0.0 };
	float translation[3] = { 0.0, 0.0, -4.0 };
	
};
myMesh * ReaderOBj(string fname2);
myMesh * ReadOffFile(const char *filename);
vector<string> split(const string &str, const string &pattern);
void get_normal(Face& face);
int getSkeleton(vector<vector<double long>>& vertexData, vector<vector<int>>& edgeData, const char* fileName, vector<int>& level, vector<double long>& radius, vector< vector<int> >& adj, std::set<int>& junctions, vector<int> & IDs, map<int, std::vector<int> > &childVertex, std::vector<vector<int> > &juncAdj);
int readAnnotation(Whorls& whorls, vector<vector<int>>& nodes, const char* fileName, vector<float>& center, vector<vector<float>>& n, map<int, int>& juncWhorlAbove, map<int, int>& juncWhorlBelow, vector<int> &inord);

//jetcolor:
COLOR GetColor(double v, double vmin, double vmax);

void propagate(vector<vector<int>>& adj, vector<int> &level, int &hierarchyCap, int v, int pv, int paridx, int diff);
void dfsid(int at, int par, vector< vector<int> >& adj, std::set<int> &junctions, vector<int> & IDs);

void directedDFS(int at, int par, int ppjunc, const std::set<int> &junctions, const vector<vector<int>> &adj, const vector<int> &level, map<int, std::vector<int> > &childVertex, std::vector<vector<int>> &juncAdj);