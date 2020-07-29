#pragma once

#include "geo2d.h"
#include "game_object.h"

template <typename Obj>
class Collider : public GameObject
{
    bool Collide(const GameObject& that) const override
    {
        return that.CollideWith(static_cast<const Obj&>(*this));
    }
};

class Unit : public Collider<Unit>
{
public:
    explicit Unit(geo2d::Point position)
            : _pos(position)
    {}

    geo2d::Point GetPos() const
    {
        return _pos;
    }

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;
private:
    geo2d::Point _pos;
};

class Building : public Collider<Building>
{
public:
    explicit Building(geo2d::Rectangle geometry)
            : _geom(geometry)
    {}

    geo2d::Rectangle GetPos() const
    {
        return _geom;
    }

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;
private:
    geo2d::Rectangle _geom;
};

class Tower : public Collider<Tower>
{
public:
    explicit Tower(geo2d::Circle geometry)
            : _geom(geometry)
    {}

    geo2d::Circle GetPos() const
    {
        return _geom;
    }

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;
private:
    geo2d::Circle _geom;
};

class Fence : public Collider<Fence>
{
public:
    explicit Fence(geo2d::Segment geometry)
            : _geom(geometry)
    {}

    geo2d::Segment GetPos() const
    {
        return _geom;
    }

    bool CollideWith(const Unit& that) const override;
    bool CollideWith(const Building& that) const override;
    bool CollideWith(const Tower& that) const override;
    bool CollideWith(const Fence& that) const override;
private:
    geo2d::Segment _geom;
};

#define CALL_COLLIDE_WITH(Class, ArgClass) \
    bool Class::CollideWith(const ArgClass& that) const \
    { \
        return geo2d::Collide(this->GetPos(), that.GetPos()); \
    }
