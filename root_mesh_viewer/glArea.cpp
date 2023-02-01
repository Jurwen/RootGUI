#include "glArea.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>
#define SCALE_FACTOR 0.005f
GLfloat LightAmbient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
static GLfloat light0_position[] = { 4.0, 4.0, 4.0, 0.0 };
static GLfloat light1_position[] = { -3.0, -3.0, -3.0, 0.0 };

int ID = 1;

void dfsid(int at, int par, vector< vector<int> >& adj, std::set<int> &junctions, vector<int> & IDs)
{
	IDs[at] = ID;
	for(const auto &nx : adj[at])
		if (nx != par)
		{
			if (junctions.count(nx)) ID++;
			dfsid(nx, at, adj, junctions, IDs);
		}
	return;
}


int getSkeleton(vector<vector<double long>>& vertexData, vector<vector<int>>& edgeData, const char* fileName, vector<int>& level, vector<double long>& radius, vector< vector<int> >& adj, std::set<int> &junctions, vector<int> & IDs) {
	// ofstream fout("getSkeleton.txt");
	
	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open()) { // a checker to see if the file is opened properly.
		vertexData.clear();
		edgeData.clear();
		radius.clear();
		level.clear();
		adj.clear();

		string word, line;
		double long verCoordinate;
		int edgeIndices;
		int lineNum = 0;
		int row = 0;
		int vNum = 0;
		int eNum = 0;
		while (getline(myFile, line)) {
			lineNum++;
			if (lineNum == 3) {
				istringstream iss(line);
				int col = 0;
				while (iss >> word) {
					if (col == 1) {
						iss >> row;
						vNum = row;
					}
					col++;
				}
			}
			if (lineNum == 10) {
				istringstream iss(line);
				int col = 0;
				while (iss >> word) {
					if (col == 1) {
						iss >> row;
						eNum = row;
					}
					col++;
				}
			}
			if (lineNum >= 16 && lineNum < 16 + vNum) {
				vector<double long> vertex;
				istringstream iss(line);
				int col = 0;
				while (iss >> verCoordinate) {
					if (col == 0) {
						int hierarchy;
						iss >> hierarchy;
						level.push_back(hierarchy);
						double long rad;
						iss >> rad;
						radius.push_back(rad);
						col += 2;
					}
					if (col == 3 || col == 4 || col == 5) {
						vertex.push_back(verCoordinate*4/6);
					}
					col++;
				}
				vertexData.push_back(vertex);
			}
			
			// ###
			adj.resize(vNum + 3);
			if (lineNum >= 16 + vNum && lineNum < 16 + vNum + eNum) {
				vector<int> edge;
				istringstream iss(line);
				while (iss >> edgeIndices) {
					edge.push_back(edgeIndices);
				}

				// assume edges connect 2 vertices
				adj[edge[0]].push_back(edge[1]);
				adj[edge[1]].push_back(edge[0]);

				edgeData.push_back(edge);
			}
		}

		for (int i = 0; i < adj.size(); i++)
			if (adj[i].size() > 2)
				junctions.insert(i);

		ID = 1;
		IDs.resize(adj.size());
		dfsid(*junctions.begin(), -1, adj, junctions, IDs);

		// fout << "Success" << endl;
		//From here, all the data from the file is been put into fileData. 
		myFile.close();
		return 1;
	}
	else { // when the file is not opened after calling the open function, display an error msg.
		// fout << "Error/ Cannot open the file" << endl;
		return 0;
	}
}

vector<string> split(const string &str, const string &pattern)
{
	//const char* convert to char*
	char * strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());
	vector<string> resultVec;
	char* tmpStr = strtok(strc, pattern.c_str());
	while (tmpStr != NULL)
	{
		resultVec.push_back(string(tmpStr));
		tmpStr = strtok(NULL, pattern.c_str());
	}

	delete[] strc;

	return resultVec;
}

myMesh * ReaderOBj(string fname2) {
	string line;
	fstream f;
	f.open(fname2, ios::in);
	if (!f.is_open()) {
		cout << "not opened" << endl;
	}
	vector<vector<GLfloat>> vset;
	vector<vector<GLint>> fset;
	int v_counter = 1;
	int f_counter = 1;
	while (!f.eof()) {
		getline(f, line);
		vector<string>parameters;
		string tailMark = " ";
		string ans = "";
		line = line.append(tailMark);
		if (line[0] != 'v'&&line[0] != 'f') {
			continue;
		}
		for (int i = 0; i < line.length(); i++) {
			char ch = line[i];
			if (ch != ' ') {
				ans += ch;
			}
			else {
				if (ans != "") {
					parameters.push_back(ans);
					ans = "";
				}
			}
		}
		cout << endl;
		if (parameters[0] == "v") {  
			vector<GLfloat>Point;
			v_counter++;
			//            cout <<atof( parameters[1].c_str()) << "--" << atof( parameters[2].c_str()) <<" --  " << atof( parameters[3].c_str());
			Point.push_back(atof(parameters[1].c_str()));
			Point.push_back(atof(parameters[2].c_str()));
			Point.push_back(atof(parameters[3].c_str()));
			vset.push_back(Point);
		}
		else if (parameters[0] == "f") {  
			vector<GLint>vIndexSets;        
			for (int i = 1; i < 4; i++) {
				string x = parameters[i];
				string ans = "";
				for (int j = 0; j < x.length(); j++) {   //Ìø¹ý¡®/¡¯
					char ch = x[j];
					if (ch != '/') {
						ans += ch;
					}
					else {
						break;
					}
				}
				vector<string >res = split(ans, "/");
				int index = atof(res[0].c_str());
				index--;
				vIndexSets.push_back(index);
			}
			fset.push_back(vIndexSets);
		}

	}
	f.close();
	myMesh *meshs = new myMesh();      
	int vert_number = vset.size();
	int face_number = fset.size();
	meshs->verts = new Vertex[vert_number + 1];
	assert(meshs->verts);

	for (int i = 0; i < vset.size(); i++)
	{
		Vertex& vert = meshs->verts[meshs->vert_number++];
		vert.x = vset[i][0];
		vert.y = vset[i][1];
		vert.z = vset[i][2];
	}

	meshs->faces = new Face[face_number];
	assert(meshs->faces);
	for (int i = 0; i < fset.size(); i++)
	{
		Face a;
		a.vert_number = fset[i].size();
		a.verts = new Vertex*[fset[i].size()];
		for (int j = 0; j < fset[i].size(); j++) {
			a.verts[j] = &meshs->verts[fset[i][j]];
		}
		get_normal(a);
		meshs->faces[meshs->face_number++] = a;
	}
	return meshs;
}

int readAnnotation(Whorls& whorls, vector<vector<int>>& nodes, const char* fileName, vector<float>& center, vector<vector<float>>& n) {

	ifstream myFile;
	myFile.open(fileName);
	if (myFile.is_open()) { // a checker to see if the file is opened properly.
		whorls.whorlAbove.clear();
		whorls.whorlBelow.clear();
		nodes = { {},{} };
		center = {};
		n = { {},{},{} };
		vector<vector<int>> totalWhorls;
		vector<vector<int>> totalNodes;
		string line;
		int word;
		float word_float;
		int infoSection = -1;
		int axis_num = 0;
		while (getline(myFile, line)) {
			if (line == "1" || line == "2" || line == "3" || line == "4" || line == "5" || line == "6" || line == "7" || line == "8" || line == "9" || line == "10") {
				infoSection = 0;
				//cout << "1:" << endl;
				getline(myFile, line);
			}
			if (line == "Whorls:") {
				infoSection = 1;
				cout << "Whorls:" << endl;
				getline(myFile, line);
			}
			if (line == "Nodal roots above and below soil:") {
				infoSection = 2;
				cout << "Nodal roots above and below soil:" << endl;
				getline(myFile, line);
			}
			else if (line == "Whorls above and below soil:") {
				infoSection = 3;
				cout << "Whorls above and below soil:" << endl;
				getline(myFile, line);
			}
			else if (line == "Plane parameters:") {
				infoSection = 4;
				cout << "Plane parameters:" << endl;
				getline(myFile, line);
			}
			else if (line == "Plane PCA:") {
				infoSection = 5;
				cout << "Plane PCA:" << endl;
				getline(myFile, line);
			}
			if (infoSection == 0) {
				istringstream iss(line);
				vector<int> someBranch;
				while (iss >> word) {
					cout << word << endl;
					someBranch.push_back(word);
				}
				totalNodes.push_back(someBranch);
			}
			if (infoSection == 1) {
				istringstream iss(line);
				vector<int> someWhorl;
				while (iss >> word) {
					someWhorl.push_back(word);
				}
				totalWhorls.push_back(someWhorl);
			}
			if (infoSection == 2) {
				istringstream iss(line);
				int branchNum;
				while (iss >> word) {
					branchNum = word;
					iss >> word;
					if (word == 1) {
						for (int i = 0; i < totalNodes[branchNum].size(); i++) {
							nodes[0].push_back(totalNodes[branchNum][i]);
						}
					}
					else {
						for (int i = 0; i < totalNodes[branchNum].size(); i++) {
							nodes[1].push_back(totalNodes[branchNum][i]);
						}
					}
				}
			}
			if (infoSection == 3) {
				istringstream iss(line);
				int whorlNum;
				while (iss >> word) {
					whorlNum = word;
					iss >> word;
					if (word == 1) {
						whorls.whorlAbove.push_back(totalWhorls[whorlNum]);
						cout << whorlNum << " - above the soil: " << endl;
						for (int i = 0; i < totalWhorls[whorlNum].size(); i++) {
							cout << whorls.whorlAbove[whorlNum][i] << endl;
						}
					}
					else {
						whorls.whorlBelow.push_back(totalWhorls[whorlNum]);
						cout << whorlNum << " - below the soil: " << endl;
						for (int i = 0; i < totalWhorls[whorlNum].size(); i++) {
							cout << whorls.whorlBelow[whorlNum][i] << endl;
						}
					}
				}
			}
			if (infoSection == 4) {
				istringstream iss(line);
				while (iss >> word_float) {
					center.push_back(word_float*4/6);
				}
			}
			if (infoSection == 5) {

				istringstream iss(line);
				while (iss >> word_float) {
					n[axis_num].push_back(word_float * 4 / 6);
				}
				axis_num++;
			}

		}
		//From here, all the data from the file is been put into fileData. 
		myFile.close();
		return 1;
	}
	else { // when the file is not opened after calling the open function, display an error msg.
		cout << "Error/ Cannot open the file" << endl;
		return 0;
	}
}

void get_normal(Face& face) {
	face.normal[0] = face.normal[1] = face.normal[2] = 0;
	Vertex *v1 = face.verts[face.vert_number - 1];
	for (int i = 0; i < face.vert_number; i++) {
		Vertex *v2 = face.verts[i];
		face.normal[0] += (v1->y - v2->y) * (v1->z + v2->z);
		face.normal[1] += (v1->z - v2->z) * (v1->x + v2->x);
		face.normal[2] += (v1->x - v2->x) * (v1->y + v2->y);
		v1 = v2;
	}
	float squared_normal_length = 0.0;
	squared_normal_length += face.normal[0] * face.normal[0];
	squared_normal_length += face.normal[1] * face.normal[1];
	squared_normal_length += face.normal[2] * face.normal[2];
	float normal_length = sqrt(squared_normal_length);
	if (normal_length > 1.0E-6) {
		face.normal[0] /= normal_length;
		face.normal[1] /= normal_length;
		face.normal[2] /= normal_length;
	}
}

//get off info
myMesh * ReadOffFile(const char *filename)
{
	int i;
	FILE *fp;                                      
	if (!(fp = fopen(filename, "r"))) {
		cout << "fail to open" << endl;
	}
	myMesh *mesh = new myMesh();
	int vert_number = 0;
	int face_number = 0;
	int line_number = 0;
	int line_count = 0;
	char buffer[1024];
	while (fgets(buffer, 1023, fp)) {
		line_count++;
		char *bufferp = buffer;
		while (isspace(*bufferp)) bufferp++;
		if (*bufferp == '#') continue;
		if (*bufferp == '\0') continue;
		if (vert_number == 0) {
			if (!strstr(bufferp, "OFF")) {
				if ((sscanf(bufferp, "%d%d%d", &vert_number, &face_number, &line_number) != 3) || (vert_number == 0)) {
					fclose(fp);
					return NULL;
				}
				cout << "aa" << vert_number << "--" << face_number << endl;
				mesh->verts = new Vertex[vert_number];
				assert(mesh->verts);
				mesh->faces = new Face[face_number];
				assert(mesh->faces);
			}
		}
		else if (mesh->vert_number < vert_number) {
			Vertex& vert = mesh->verts[mesh->vert_number++];
			if (sscanf(bufferp, "%f%f%f", &(vert.x), &(vert.y), &(vert.z)) != 3) {
				fclose(fp);
				return NULL;
			}
		}
		else if (mesh->face_number < face_number) {
			Face& face = mesh->faces[mesh->face_number++];
			bufferp = strtok(bufferp, " \t");
			if (bufferp) face.vert_number = atoi(bufferp);
			else {
				fclose(fp);
				return NULL;
			}
			face.verts = new Vertex *[face.vert_number];
			assert(face.verts);
			for (i = 0; i < face.vert_number; i++) {
				bufferp = strtok(NULL, " \t");
				if (bufferp) face.verts[i] = &(mesh->verts[atoi(bufferp)]);
				else {
					fprintf(stderr, "Syntax error with face on line %d in file %s\n", line_count, filename);
					fclose(fp);
					return NULL;
				}
			}
			get_normal(face);
		}
		else {
			break;
		}
	}
	if (face_number != mesh->face_number) {
	}
	fclose(fp);
	return mesh;
}
GLuint faceName;
GLuint lineName;

glArea::glArea(QWidget *parent) :QOpenGLWidget(parent) {
	cout << "creating GLArea." << endl;
	vertexList = { {0} };
	edgeList = { {0} };
	level = {0};
	radius = {0};
	/*if (getSkeleton(vertexList, edgeList, "591-4-topo-with-plane.ply", level, radius) == 1) {
		cout << "Successfully initiated ply data... " << endl;
	}*/
	mesh = ReadOffFile("2020_PlantHaven_RT_591-4_2021-rewash_109um.off");
	/*mesh = ReaderOBj("smooth.obj");*/
	cout << "Sucessfully initiated mesh data..." << endl;
	if (readAnnotation(whorls, nodalRoots, "591-4-topo-with-plane-annotations.txt", cent, n) == 1) {
		cout << "Successfully initiated annotation data..." << endl;
	}
	isRotate = false;
	isTranslate = false;
	if_face = false;
	if_line = false;
	if_drawWhorlAbove = false;
	if_drawWhorlBelow = false;
	if_drawNodeAbove = false;
	if_drawNodeBelow = false;
	if_drawPlane = false;
	editOn = false;
	alpha = 0.5;
	line_width = 1.0;
	line_color = Normal;
	mesh_colorR = 1.0;
	mesh_colorG = 1.0;
	mesh_colorB = 1.0;
	back_colorR = 1.0;
	back_colorG = 1.0;
	back_colorB = 1.0;
	jet_max = (double)*max_element(radius.begin(), radius.end());
	jet_min = (double)*min_element(radius.begin(), radius.end());
}

glArea::~glArea()
{
}

void glArea::draw_rootsAbove() {
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < nodalRoots[0].size(); i++) {
		glVertex3f(vertexList[nodalRoots[0][i]][0], vertexList[nodalRoots[0][i]][1], vertexList[nodalRoots[0][i]][2]);
	}
	glEnd();
}

void glArea::draw_plane() {
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glBegin(GL_QUADS);
	glVertex3f(cent[0] + 100 * n[1][0] + 100 * n[2][0], cent[1] + 100 * n[1][1] + 100 * n[2][1], cent[2] + 100 * n[1][2] + 100 * n[2][2]);
	glVertex3f(cent[0] + 100 * n[1][0] - 100 * n[2][0], cent[1] + 100 * n[1][1] - 100 * n[2][1], cent[2] + 100 * n[1][2] - 100 * n[2][2]);
	glVertex3f(cent[0] - 100 * n[1][0] - 100 * n[2][0], cent[1] - 100 * n[1][1] - 100 * n[2][1], cent[2] - 100 * n[1][2] - 100 * n[2][2]);
	glVertex3f(cent[0] - 100 * n[1][0] + 100 * n[2][0], cent[1] - 100 * n[1][1] + 100 * n[2][1], cent[2] - 100 * n[1][2] + 100 * n[2][2]);
	glEnd();
}

void glArea::draw_rootsBelow() {
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glPointSize(3.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < nodalRoots[1].size(); i++) {
		glVertex3f(vertexList[nodalRoots[1][i]][0], vertexList[nodalRoots[1][i]][1], vertexList[nodalRoots[1][i]][2]);
	}
	glEnd();
}

void glArea::draw_whorlsAbove() {
	glColor4f(1.0, 0.0, 0.0, 1.0);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	vector<vector<vector<float>>> whorlBbox; //whorl bounding box: 
	for (int i = 0; i < whorls.whorlAbove.size(); i++) {
		vector<vector<float>> oneBBox = { {},{},{} };
		for (int j = 0; j < whorls.whorlAbove[i].size(); j++) {
			int vertexNum = whorls.whorlAbove[i][j];
			oneBBox[0].push_back(vertexList[vertexNum][0]);
			oneBBox[1].push_back(vertexList[vertexNum][1]);
			oneBBox[2].push_back(vertexList[vertexNum][2]);
			glVertex3f(vertexList[vertexNum][0], vertexList[vertexNum][1], vertexList[vertexNum][2]);
		}
		whorlBbox.push_back({ { *min_element(oneBBox[0].begin(),oneBBox[0].end())-3,*min_element(oneBBox[1].begin(),oneBBox[1].end())-3,*min_element(oneBBox[2].begin(),oneBBox[2].end())-3 },
			{*max_element(oneBBox[0].begin(),oneBBox[0].end())+3,*max_element(oneBBox[1].begin(),oneBBox[1].end())+3,*max_element(oneBBox[2].begin(),oneBBox[2].end())+3} });
	}
	glEnd();
	glBegin(GL_LINES);
	for (int i = 0; i < whorlBbox.size(); i++) {
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		//front square
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		//back square
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		//middle edges
	}
	glEnd();
}

void glArea::draw_whorlsBelow() {
	glColor4f(0.0, 0.0, 1.0, 1.0);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	vector<vector<vector<float>>> whorlBbox; //whorl bounding box: 
	for (int i = 0; i < whorls.whorlBelow.size(); i++) {
		vector<vector<float>> oneBBox = { {},{},{} };
		for (int j = 0; j < whorls.whorlBelow[i].size(); j++) {
			int vertexNum = whorls.whorlBelow[i][j];
			oneBBox[0].push_back(vertexList[vertexNum][0]);
			oneBBox[1].push_back(vertexList[vertexNum][1]);
			oneBBox[2].push_back(vertexList[vertexNum][2]);
			glVertex3f(vertexList[vertexNum][0], vertexList[vertexNum][1], vertexList[vertexNum][2]);
		}
		whorlBbox.push_back({ { *min_element(oneBBox[0].begin(),oneBBox[0].end()) - 3,*min_element(oneBBox[1].begin(),oneBBox[1].end()) - 3,*min_element(oneBBox[2].begin(),oneBBox[2].end()) - 3 },
			{*max_element(oneBBox[0].begin(),oneBBox[0].end()) + 3,*max_element(oneBBox[1].begin(),oneBBox[1].end()) + 3,*max_element(oneBBox[2].begin(),oneBBox[2].end()) + 3} });
	}
	glEnd();
	glBegin(GL_LINES);
	for (int i = 0; i < whorlBbox.size(); i++) {
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		//front square
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		//back square
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][0][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][1][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][0][2]);
		glVertex3f(whorlBbox[i][0][0], whorlBbox[i][1][1], whorlBbox[i][1][2]);
		//middle edges
	}
	glEnd();
}

void glArea::draw_faces() {
	faceName = glGenLists(faceDisplayList);
	glNewList(faceName, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < mesh->face_number; i++) {
		Face& face = mesh->faces[i];
		glNormal3fv(face.normal);
		for (int j = 0; j < face.vert_number; j++) {
			Vertex *vert = face.verts[j];
			glVertex3f(vert->x, vert->y, vert->z);
		}
	}
	glEnd();
	glEndList();
}



// CHECK HERE FOR JUNCTION POINT COLORING ERRORS
void glArea::draw_lines() {
	// ofstream fout("draw_lines.txt");
	// fout << "Drawing lines..." << endl;
	if (line_color == Normal) {
		// fout << "Drawing Normal lines..." << endl;
		glColor4f(0.0, 0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		for (int j = 0; j < edgeList.size(); j++) {
			// fout << edgeList[j][0] << " " << edgeList[j][1] << endl;
			glVertex3f(vertexList[edgeList[j][0]][0], vertexList[edgeList[j][0]][1], vertexList[edgeList[j][0]][2]);
			glVertex3f(vertexList[edgeList[j][1]][0], vertexList[edgeList[j][1]][1], vertexList[edgeList[j][1]][2]);
		}
		glEnd();
		// fout << "Finished drawing Normal lines..." << endl;
	}
	else if (line_color == Jet) {
		glBegin(GL_LINES);
		for (int j = 0; j < edgeList.size(); j++) {
			COLOR edge_color = GetColor(radius[edgeList[j][0]]+ radius[edgeList[j][1]]/2, jet_min, jet_max);
			glColor4f((float)edge_color.r, (float)edge_color.g, (float)edge_color.b, 1.0);
			glVertex3f(vertexList[edgeList[j][0]][0], vertexList[edgeList[j][0]][1], vertexList[edgeList[j][0]][2]);
			glVertex3f(vertexList[edgeList[j][1]][0], vertexList[edgeList[j][1]][1], vertexList[edgeList[j][1]][2]);
		}
		glEnd();
	}
	else if (line_color == Hierarchy) {
		// fout << "Drawing hierarchal lines..." << endl;
		glBegin(GL_LINES);
		int maxLvl = (double)*max_element(level.begin(), level.end());
		
		// fout << hierarchyCap << endl;
		// fout << maxLvl << endl;
		if (maxLvl > hierarchyCap) { maxLvl = hierarchyCap; }; //hierarchy view fixed to have hierarchyCap as max level during showing
		
		for (int j = 0; j < edgeList.size(); j++) {
			// changed edgelist[j][0] whenever it was used to get color
			// to the max of the two

			// fout << edgeList[j][0] << " " << edgeList[j][1] << endl;
			if (showLevels[max(level[edgeList[j][0]], level[edgeList[j][1]])]) {
				COLOR edge_color = GetColor((max(level[edgeList[j][0]], level[edgeList[j][1]]) > hierarchyCap)? hierarchyCap : max(level[edgeList[j][0]], level[edgeList[j][1]]), 0, maxLvl);
				
				// fout << edgeList[j][0] << " " << edgeList[j][1] << " ";
				// fout << edge_color.r << " " << edge_color.g << " " << edge_color.b << endl;

				glColor4f((float)edge_color.r, (float)edge_color.g, (float)edge_color.b, 1.0);
				glVertex3f(vertexList[edgeList[j][0]][0], vertexList[edgeList[j][0]][1], vertexList[edgeList[j][0]][2]);
				glVertex3f(vertexList[edgeList[j][1]][0], vertexList[edgeList[j][1]][1], vertexList[edgeList[j][1]][2]);
			}
		}
		glEnd();
	}
	// fout << "Successfully drew lines" << endl;
}

ofstream fout("debug.txt");

// from stackoverflow
// simply believe
void glArea::label_junction(int idx, float h) {
	//float scale = h / (119.05f + 33.33f);
	float xo = vertexList[idx][0]; // x coord
	float yo = vertexList[idx][1]; // y coord
	float zo = vertexList[idx][2]; // z coord
	// float xo = center[0], yo = center[1], zo = center[2];
	//fout << "set coords " << xo << " " << yo << " " << zo << "\n";

	glPushMatrix();
	//fout << "Pushed matrix\n";
	glTranslatef(xo, yo, zo);
	glScalef(1 / 152.38, 1 / 152.38, 1 / 200.38);
	glRotatef(270.0, 1.0, 0.0, 0.0); // find right one

	//fout << "translated and scaled\n";
	auto curr = reinterpret_cast<const unsigned char*>(to_string(idx).c_str());
	//fout << "Cast\n";

	// const unsigned char* c = reinterpret_cast<const unsigned char*>('a');
	// fout << c << "\n";
	// why crash
	glFlush();
	//int c = 'a';
	//fout << glutStrokeWidth(GLUT_STROKE_ROMAN, c) << "\n";
	//glutStrokeCharacter(GLUT_STROKE_ROMAN, 'A');
	glutStrokeString(GLUT_STROKE_ROMAN, (const unsigned char*)to_string(idx).c_str());
	glFlush();

	//fout << "stroked\n";
	glPopMatrix();
	//fout << "done\n";
}

// from stackOverflow
void glArea::draw_labels() {
	float size = 0.5f;
	float offsl = size * 0.7f;
	glColor3d(0.0, 0.0, 0.0);
	//fout << "Color setting done" << "\n";

	for (const int &i : junctions) {
		//fout << "attempting junction " << i << "\n";
		label_junction(i, size);
	}
}

void glArea::adjustView()
{
	float bbox[2][3] = { { 1.0E30F, 1.0E30F, 1.0E30F }, { -1.0E30F, -1.0E30F, -1.0E30F } };
	for (int i = 0; i < mesh->vert_number; i++) {
		Vertex& vert = mesh->verts[i];
		if (vert.x < bbox[0][0]) bbox[0][0] = vert.x;
		else if (vert.x > bbox[1][0]) bbox[1][0] = vert.x;
		if (vert.y < bbox[0][1]) bbox[0][1] = vert.y;
		else if (vert.y > bbox[1][1]) bbox[1][1] = vert.y;
		if (vert.z < bbox[0][2]) bbox[0][2] = vert.z;
		else if (vert.z > bbox[1][2]) bbox[1][2] = vert.z;
	}
	// Setup initial viewing scale
	float dx = bbox[1][0] - bbox[0][0];
	float dy = bbox[1][1] - bbox[0][1];
	float dz = bbox[1][2] - bbox[0][2];
	scale = 2.0 / sqrt(dx*dx + dy * dy + dz * dz);
	// Setup initial viewing center
	center[0] = 0.5 * (bbox[1][0] + bbox[0][0]);
	center[1] = 0.5 * (bbox[1][1] + bbox[0][1]);
	center[2] = 0.5 * (bbox[1][2] + bbox[0][2]);
}


void glArea::initializeGL()
{
	
	//draw_faces();
	//draw_lines();
	GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	GLfloat light0_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
	glEnable(GL_LIGHT0);
	GLfloat light1_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	//glEnable(GL_DEPTH_TEST);


	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glEnable(GL_LINE_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLightModeli(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	//adjustView();
	
}

void glArea::resizeGL(int width, int height)
{
	GLUTwindow_width = width;
	GLUTwindow_height = height;
	glViewport(0, 0, (GLint)width, (GLint)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)GLUTwindow_width / (GLfloat)GLUTwindow_height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void glArea::paintGL()
{
	glLoadIdentity();
	glScalef(scale, scale, scale);
	glTranslatef(translation[0], translation[1], 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)GLUTwindow_width / (GLfloat)GLUTwindow_height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(translation[0], translation[1], translation[2]);
	glScalef(scale, scale, scale);
	glRotatef(rotation[0], 1.0, 0.0, 0.0);
	glRotatef(rotation[1], 0.0, 1.0, 0.0);
	glRotatef(rotation[2], 0.0, 0.0, 1.0);
	glTranslatef(-center[0], -center[1], -center[2]);
	glClearColor(back_colorR, back_colorG, back_colorB, 1.0);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
	glColor4f(mesh_colorR, mesh_colorG, mesh_colorB, alpha);
	if (if_face) { glCallList(faceName); /*draw_faces();*/ }
	/*glColor4f(0.0, 0.0, 0.0, 1.0);*/
	glLineWidth(line_width);
	if (if_line) { /*glCallList(lineName);*/ draw_lines();  }
	if (if_drawWhorlAbove&&annotation_activated == 2) {  draw_whorlsAbove(); }
	if (if_drawWhorlBelow&&annotation_activated == 2) {  draw_whorlsBelow(); }
	if (if_drawNodeAbove&&annotation_activated == 2) { draw_rootsAbove(); }
	if (if_drawNodeBelow&&annotation_activated == 2) { draw_rootsBelow(); }
	if (if_drawPlane&&annotation_activated == 2) { draw_plane(); }
	if (editOn) { draw_labels(); }
	glFlush();
	update();
}

void glArea::mousePressEvent(QMouseEvent * event)
{
	if (event->buttons() == Qt::LeftButton) {
		isRotate = true;
		isTranslate = false;
	}
	else if (event->buttons() == Qt::RightButton) {
		isTranslate = true;
		isRotate = false;
	}
	GLUTmouse[0] = event->pos().x();
	GLUTmouse[1] = event->pos().y();
}

void glArea::mouseMoveEvent(QMouseEvent * event)
{
	if (isRotate) {
		rotation[0] -= -0.5 * (event->pos().y() - GLUTmouse[1]);
		rotation[2] -= 0.5 * (event->pos().x() - GLUTmouse[0]);
	}
	if (isTranslate) {
		translation[0] += 2.0 * (float)(event->pos().x() - GLUTmouse[0]) / (float)GLUTwindow_width;
		translation[1] -= 2.0 * (float)(event->pos().y() - GLUTmouse[1]) / (float)GLUTwindow_height;
	}
	GLUTmouse[0] = event->pos().x();
	GLUTmouse[1] = event->pos().y();
}

void glArea::mouseReleaseEvent(QMouseEvent * event)
{

}

void glArea::wheelEvent(QWheelEvent * event)
{
	if (event->delta() > 0) {
		if (scale > SCALE_FACTOR)
			scale -= SCALE_FACTOR;
	}
	else {
		if (scale < SCALE_FACTOR * 30.0f)
			scale += SCALE_FACTOR;
	}
}

COLOR GetColor(double v, double vmin, double vmax) //code from stack overflow
{
	COLOR c = { 1.0,1.0,1.0 }; // white
	double dv;

	if (v < vmin)
		v = vmin;
	if (v > vmax)
		v = vmax;
	dv = vmax - vmin;

	if (v < (vmin + 0.25 * dv)) {
		c.r = 0;
		c.g = 4 * (v - vmin) / dv;
	}
	else if (v < (vmin + 0.5 * dv)) {
		c.r = 0;
		c.b = 1 + 4 * (vmin + 0.25 * dv - v) / dv;
	}
	else if (v < (vmin + 0.75 * dv)) {
		c.r = 4 * (v - vmin - 0.5 * dv) / dv;
		c.b = 0;
	}
	else {
		c.g = 1 + 4 * (vmin + 0.75 * dv - v) / dv;
		c.b = 0;
	}

	return(c);
}

// ofstream prop("propagate.txt");
void propagate(vector<vector<int>>& adj, vector<int>& level, int& hierarchyCap, int vertex, int pv, int diff)
{
	// prop <<  "at " <<  vertex << " w/ level " << level[vertex] << "\n";
	/*for (int i = 0; i < level.size(); i++)
		prop << level[i] << " ";
	prop << "\n";
	*/
	for (const auto &nx : adj[vertex])
	{
		if (nx != pv)
		{
			// prop << nx << " " << level[nx] << " " << diff << "\n";
			level[nx] += diff;
			//hierarchyCap = max(level[nx], hierarchyCap);
			propagate(adj, level, hierarchyCap, nx, vertex, diff);
		}
	}
	// prop << "RETURNED\n";
}