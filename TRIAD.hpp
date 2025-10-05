#ifndef TRIAD_H
#define TRIAD_H
#include <Eigen/Dense>
//Apply TRIAD algorithm to determine the attitude from
//measured magnetic field and sun vectors in body frame
//and inertial frame

class TRIAD {
public:
    static Eigen::Matrix3d attitude(Eigen::Vector3d& body_sun, Eigen::Vector3d& body_magnetic, 
        Eigen::Vector3d& ref_sun, Eigen::Vector3d& ref_magnetic) { 
        //Notation note: they are measured sun & magnetic field vectors in body 
        //frame, and the true sun & magnetic field vectors (in inertial reference
        //frame), respectively

        //Normalizing
        Eigen::Vector3d v1 = body_sun.normalized();
        Eigen::Vector3d v2 =(v1.cross(body_magnetic)).normalized();
        Eigen::Vector3d v3 = v1.cross(v2);
        Eigen::Matrix3d body;
        body << v1, v2, v3;

        Eigen::Vector3d u1 = ref_sun.normalized();
        Eigen::Vector3d u2 = (u1.cross(ref_magnetic)).normalized();
        Eigen::Vector3d u3 = u1.cross(u2);
        Eigen::Matrix3d ref;
        ref << u1, u2, u3;

        return body * ref.transpose();
    }
};

#endif