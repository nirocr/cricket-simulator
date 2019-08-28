pipeline {
  agent any
  stages {
    stage('Infrastructure') {
      steps {
        echo 'Infrastructure'
        sh 'ls -al'
      }
    }
    stage('Build') {
      steps {
        echo 'Build'
        sh 'make'
      }
    }
    stage('Static Analysis') {
      steps {
        echo 'Static Analysis'
      }
    }
    stage('System Test') {
      steps {
        echo 'System Test'
      }
    }
    stage('Security Scan') {
      steps {
        echo 'Security Scan'
      }
    }
  }
}
