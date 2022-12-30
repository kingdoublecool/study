class Party {

}

class Employee extends Party {
  constructor(name, id, monthlyConst) {
    super();
    this._id = id;
    this._name = name;
    this._monthlyCost = monthlyConst;
  }
}

class Department extends Party {
  constructor(name, staff) {
    super();
    this._name = name;
    this._staff = staff;
  }
}
