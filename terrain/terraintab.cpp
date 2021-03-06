#include "terrain/terraintab.h"



TerrainTab::TerrainTab(const TerrainTab& copy):
        height(copy.height),    width(copy.width),  amplitude(copy.amplitude), hauteurMin(copy.hauteurMin), hauteurMax(copy.hauteurMax)
{
    longueur = copy.longueur;
    largeur = copy.largeur;
    box = copy.box;
    grille = new float[height*width];
    for(int i = 0;  i < height*width;   i++)
        grille[i] = copy.grille[i];
    grille2d = new float*[height];
    for(int j = 0;  j < height; j++)
        grille2d[j] = &grille[j*width];
}

TerrainTab::~TerrainTab()
{
    if(grille != nullptr)
    {
        delete[] grille;
        for(int j = 0;  j < height; j++)
            delete[] grille2d;
    }
}

inline float TerrainTab::get(int x, int y) const
{
    return grille2d[y][x];
}

float TerrainTab::getHauteur(float x, float y) const
{
    x /= largeur;
    y /= longueur;
    if(x < 0 || y < 0 || x > 1 || y > 1)
        return HAUTEUR_HORS_MAP;


    x *= (width-1),    //largeur: 1m et 5 points: (1.0f*(5-1))/1 = 4.0f donc regarder l'indice 4
    y *= (height-1);

    int x1 = floorf(x),
        y1 = floorf(y),
        x2 = ceilf(x),
        y2 = ceilf(y);

    const float h11 = get(x1, y1);

    if(y1 == y2)    {
        if(x1 == x2 )
            return h11*amplitude;
        return interp::interp_linear1D(x, h11, get(x2, y1))*amplitude;
    }
    else    {
        float h12 = get(x1, y2);
        if(x1 == x2 )
            return interp::interp_linear1D(x, h11, h12)*amplitude;
        return interp::interp_linear2D(x, y, x1, y1, x2, y2,
                                       h11, h12, get(x2, y1), get(x2, y2))*amplitude;
    }
}



vec3 TerrainTab::getNormal(float x, float y, float eps) const
{

    if(x < 0 || y < 0 || x > largeur || y > longueur)
        return vec3(0,0,1);

    float ha = getHauteur(x,y);
    float   xg = std::max(x-eps, 0.f),
            xd = std::min(x+eps, largeur),
            yb = std::min(y+eps, longueur),
            yh = std::max(y-eps, 0.f);
    float       g = getHauteur(xg,y),
                d = getHauteur(xd,y),
                b = getHauteur(x,yb),
                h = getHauteur(x,yh);
    vec3    vg(-eps, 0, g-ha),
            vd(eps, 0, d-ha),
            vb(0, eps, b-ha),
            vh(0, -eps, h-ha);
    float       distg = length(vg),
                distd = length(vd),
                distb = length(vb),
                disth = length(vh);
    vec3    v1 = cross(vg,vh),
            v2 = cross(vh,vd),
            v3 = cross(vd,vb),
            v4 = cross(vb,vg);
    vec3 normale(0,0,0);
    if(distg*disth > 0)
        normale += normalize(v1)*distg*disth;
    if(disth*distd > 0)
        normale += normalize(v2)*disth*distd;
    if(distd*distb > 0)
        normale += normalize(v3)*distd*distb;
    if(distb*distg > 0)
        normale += normalize(v4)*distb*distg;
    normale = normalize(normale);
    return normale;
}


/*******************************Image********************************/


TerrainTab::TerrainTab(const QImage &img, float longueur, float largeur, float amplitude):
    Terrain(longueur,largeur,amplitude),    height(img.height()), width(img.width()), amplitude(amplitude)
{
    initGrille();
    simpleInitImage(img);
    updateElevation();
}


TerrainTab::TerrainTab(const QImage& img, int _nbHeight, int _nbWidth, float longueur, float largeur, float amplitude):
    Terrain(longueur,largeur,amplitude), height(_nbHeight), width(_nbWidth), amplitude(amplitude)
{
    initGrille();
    if(_nbHeight == img.height() && _nbWidth == img.width())
        simpleInitImage(img);
    else
    {
        for(int j = 0;  j < _nbHeight;   j++)
        {
            float y = j*(float)(img.height()-1)/(_nbHeight-1);
            int y1 = floorf(y), y2 = ceilf(y);
            for(int i = 0;  i < _nbWidth;    i++)
            {
                float x = i*(float)(img.width()-1)/(_nbWidth-1);
                int x1 = floorf(x), x2 = ceilf(x);
                float z = interp::interp_hermite2D(x,y,
                                                  x1,y1,x2,y2,
                                                  qGray(img.pixel(x1, y1))/255.0,
                                                  qGray(img.pixel(x1, y2))/255.0,
                                                  qGray(img.pixel(x2, y1))/255.0,
                                                  qGray(img.pixel(x2, y2))/255.0
                                                  );
                grille2d[j][i] = z;
            }
        }
    }
    updateElevation();
}

/**construit un terrain avec le même nombre de point que le nombre de pixel de l'image*/
void TerrainTab::simpleInitImage(const QImage& img)
{
    for(int j = 0;  j < height; j++)
        for(int i = 0;  i < width; i++)
            grille2d[j][i] = qGray(img.pixel(i,j))/255.0;
}

void TerrainTab::initGrille()
{
    grille = new float[height*width];
    grille2d = new float*[height];
    for(int j = 0;  j < height; j++)
        grille2d[j] = &grille[j*width];
}

/********************************************************************************************/





float TerrainTab::minElevation() const{
    return hauteurMin; //pas bon
}
float TerrainTab::maxElevation() const{
    return hauteurMax; //pas bon
}
