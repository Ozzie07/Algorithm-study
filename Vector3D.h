template<typename TT>
class Vector3D
{
public:
	TT x_, y_, z_;

	Vector3D()
		: x_(0.0), y_(0.0), z_(0.0) {}

	Vector3D(const TT &_x, const TT &_y, const TT &_z)
		: x_(_x), y_(_y), z_(_z) {}

	void assign(const TT &_x, const TT &_y, const TT &_z)
	{
		x_ = _x;
		y_ = _y;
		z_ = _z;
	}

	void print()
	{
		std::cout << x_ << " " << y_ << " " << z_ << std::endl;
	}

	Vector3D& operator+=(const Vector3D& v_input)
	{
		x_ += v_input.x_;
		y_ += v_input.y_;
		z_ += v_input.z_;
		return *this;
	}

	TT dotProduct(const Vector3D &v0, const Vector3D &v1)
	{
		return v0.x_ *v1.x_ + v0.y_ * v1.y_ + v0.z_ * v1.z_;
	}

};

template <class TT>
Vector3D<TT> crossProduct(const Vector3D<TT> &v0, const Vector3D<TT> &v1)
{
	return Vector3D<TT>(v0.y_ * v1.z_ - v0.z_ * v1.y_, -v0.x_ * v1.z_ + v0.z_ * v1.x_, v0.x_ * v1.y_ - v0.y_ * v1.x_);
}


