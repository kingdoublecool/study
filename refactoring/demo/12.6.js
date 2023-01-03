class Employee {
  constructor(name){ 
    this._name = name; 
  }
  function createEmployee(name, type) {
    switch (type) {
      case "enginerr":
        return new Employee(name);
      case "manager": 
        return new Manager(name);
      case "salesman":
        return new Salesman(name);
      default: 
        throw new Error(`Employee cannot be of type ${type}`);
    }
  }
  toString() {
    return `${this._name} (${this.type})`;
  }
}
class Engineer extends Employee {
  get type() {return "engineer";}
}
class Salesman extends Employee {
  get type() {return "salesman";}
}
class Manager extends Employee {
  get type() {return "manager";}
}
