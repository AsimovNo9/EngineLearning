#include <iostream>
#include <math.h>

struct Vector3D{

    float x, y, z;

    Vector3D() = default;

    Vector3D(float a, float b, float c): x(a), y(b), z(c){};

    float& operator [](int i){
        return ((&x)[i]);
    }

    const float& operator[](int i) const {
        return ((&x)[i]);
    }

    Vector3D& operator*=(float s){
        x*=s;
        y*=s;
        z*=s;
        return (*this);
    }

    Vector3D& operator /=(float s){
        s = 1.0F/s;
        x*=s;
        y*=s;
        x*=s;
        return (*this);
    }

    Vector3D& operator +=(Vector3D& v){
        x+=v.x;
        y+=v.y;
        z+=v.z;
        return (*this);
    }

    Vector3D& operator -=(Vector3D& v){
        x-=v.x;
        y-=v.y;
        z-=v.z;
        return (*this);
    }
};

inline Vector3D operator *(const Vector3D& v, float s){
    return (Vector3D(v.x*s, v.y*s, v.z*s));
}

inline Vector3D operator /(const Vector3D& v, float s){
    s = 1.0F/s;
    return (Vector3D(v.x*s, v.y*s, v.z*s));
}

inline Vector3D operator -(const Vector3D& v){
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float magnitude(const Vector3D& v){
    return (sqrt(v.x*v.x+v.y*v.y+v.z*v.z));
}

inline Vector3D normalize(const Vector3D& v){
    return (v/magnitude(v));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b){
    return(Vector3D(a.x+b.x, a.y+b.y, a.z+b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b){
    return (Vector3D(a.x-b.x, a.y-b.y, a.z-b.z));
}


struct Matrix3D{
    private:
        float n[3][3];

    public:
        Matrix3D() = default;

        Matrix3D(float n00, float n01, float n02,
                float n10, float n11, float n12,
                float n20, float n21, float n22){
                    n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
                    n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
                    n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
                }

        Matrix3D(Vector3D& a, Vector3D& b, Vector3D& c){
            n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
            n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
            n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
        }

        float& operator ()(int i, int j){
            return (n[j][i]);
        }

        const float& operator ()(int i, int j) const{
            return (n[j][i]);
        }

        Vector3D& operator [](int j){
            return (*reinterpret_cast<Vector3D *>(n[j]));
        }
};