class RepositoryException(Exception):
    pass

class NotIntegerValue(Exception):
  def __init__(self, message):
    self.message = message

class NotValidString(Exception):
    pass

class NotOnlyDigits(Exception):
    pass

class NotDateFormat(Exception):
    pass

class NotInIdPersons(Exception):
    pass