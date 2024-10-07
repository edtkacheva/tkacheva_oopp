#pragma once
#include <iostream>
#include <vector>

#include "header.h"
#include "tkacheva_student.h"
#include "tkacheva_headman.h"

class tkacheva_group
{
private:
    friend class boost::serialization::access;
    vector <shared_ptr<tkacheva_student>> students;
public:
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& students;
    }
    void add_student();
    void add_headman();
    void view_students();
    void delete_students();
    virtual void save_data();
    virtual void load_data();
};